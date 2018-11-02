#encoding:utf-8
import time

def print_time(fn):
	def wrapper(*args, **kwargs):
		start = time.time()
		ret = fn(args, kwargs)
		end = time.time()
		last = end - start
		print('Last time %s' % last)
		return ret
	return wrapper

@print_time
def test(*args, **kwargs):
	print('Hello testing...')

test()
