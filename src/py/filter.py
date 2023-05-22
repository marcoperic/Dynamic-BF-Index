import hashlib

class Filter:

    def __init__(self, size, num_h) -> None:
        self.size = size
        self.num_h = num_h
        self.hash_functions = [self.h1, self.h2, self.h3]
        self.data = [0] * size
        self.length = 0

    def insert(self, element):
        hashes = []
        hashes.append()
    
    def query(self, element):
        return None
    
    def resize(self):
        return None
    
    def h1(self, x):
        h = hashlib.md5().encode(x) # does not work. need to encode string before obtaining digest
        return hash(h.digest().encode('base64')) % self.size
    
    def h2(self, x):
        temp = hashlib.sha1().update(x)
        return hash(temp.digest().encode('base64')) % self.size
    
    def h3(self, x):
        temp = hashlib.sha224(x).update(x)
        return hash(temp.digest().encode('base64')) % self.size
    
    def test(self):
        return [x('a series of unfortunate events') for x in self.hash_functions]