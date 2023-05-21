import hashlib

class Filter:

    def __init__(self, size, num_h) -> None:
        self.size = size
        self.num_h = num_h
        self.data = [0] * size
        self.length = 0

    def insert(self):
        return None
    
    def query(self):
        return None
    
    def resize(self):
        return None
    
    def h1(self, x):
        temp = hashlib.md5(x)
        return hash(temp.digest().encode('base64')) % self.size
    
    def h2(self, x):
        temp = hashlib.sha1(x)
        return hash(temp.digest().encode('base64')) % self.size
    
    def h3(self, x):
        temp = hashlib.sha224(x)
        return hash(temp.digest().encode('base64')) % self.size