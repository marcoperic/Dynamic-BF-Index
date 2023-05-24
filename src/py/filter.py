import hashlib

# TODO:
# Investigate the effects of resizing on hash positions. May be necessary to resize logarithmically to avoid complications.
# min_size can be used for this purpose. bit shifts can be used for this purpose.

class Filter:

    def __init__(self, size, num_h = 3) -> None:
        self.size = size
        self.min_size = size
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
        h = hashlib.md5()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.size
    
    def h2(self, x):
        h = hashlib.sha1()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.size
    
    def h3(self, x):
        h = hashlib.sha224()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.size
    
    # def test(self, obj):
    #     if type(obj) == str:
    #         print('str input')
    #         obj = bytes(obj, 'utf-8')
    #     else:
    #         obj = bytes(obj)
    #
    #     return [x(obj) for x in self.hash_functions]