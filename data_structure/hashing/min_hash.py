import numpy as np 

np.random.seed(20170430)

class MinHash():

    n_row = -1
    n_col = -1
    n_hash = -1

    sig_mat = None
    hash_funcs = None

    def __init__(self, n_row, n_col, n_hash):
        self.n_row = n_row
        self.n_col = n_col
        self.n_hash = n_hash
        
        self.sig_mat = np.ones((n_hash, n_col)) * np.finfo('d').max
        self._build_hash_funcs()


    def _build_hash_funcs(self):
        primes = [3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61]
        self.hash_funcs = []
        for i in range(self.n_hash):
            a = primes[i]
            self.hash_funcs.append((lambda x : (a * x + 1) % self.n_row))
        


    def build_min_hash(self, orders):

        for user, items in orders.items():
            # compute hash(r)
            hashes = []
            for h_func in self.hash_funcs:
                hashes.append(h_func(user))
            
            for item in items:
                for h in range(len(hashes)):
                    self.sig_mat[h, item] = min(self.sig_mat[h, item], hashes[h])
                


def make_orders(n_user, n_item):
    # Make temporal orders, orders[user][item] = 1 if user buys item, otherwise 0 
    orders = {}

    for user in range(n_user):
        n_item_cur_user = np.random.randint(3, 20)
        items = np.random.randint(0, n_item, size=n_item_cur_user)
        orders[user] = items
    
    return orders
        

def main():
    n_user = 200
    n_item = 100
    orders = make_orders(n_user, n_item)

    n_hash = 4
    min_hash = MinHash(n_user, n_item, n_hash)

    min_hash.build_min_hash(orders)

    print(min_hash.sig_mat[:, 0])
    print(min_hash.sig_mat[:, 1]) 


if __name__ == '__main__':
    main()

