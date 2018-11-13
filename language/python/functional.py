def lazy_sum(buf):
    def sum():
        an = 0
        for n in buf:
            an += n
        return an

    return sum

buf = range(10)

f = lazy_sum(buf)
print(f())
