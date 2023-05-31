import hashlib, math

# TODO:
# Investigate the effects of resizing on hash positions. May be necessary to resize logarithmically to avoid complications.
# min_size can be used for this purpose. bit shifts can be used for this purpose.

class Filter:

    def __init__(self, size, prob, num_h = 3) -> None:
        # self.min_size = size
        self.size = 0
        self.hash_functions = [self.h1, self.h2, self.h3]
        self.data = [0] * size
        self.length = size
        self.prob = float(1 / prob)

    def insert(self, element):
        hashes = [x(self.encode(element)) for x in self.hash_functions]
        for i in hashes: self.data[i] = 1
        
        self.size += 1
        new_prob = self.calculateFP()
        print('insertion complete - new false positive rate is ' + str(new_prob))
        # if (new_prob > self.prob): self.resize() # chance of FP too high, resize
    
    def calculateFP(self):
        k = len(self.hash_functions)
        return float(pow(1 - math.exp((-1 * k) / (self.length / self.size)), k))

    def query(self, element):
        hashes = [x(self.encode(element)) for x in self.hash_functions]
        for i in hashes:
            if (self.data[i] == 0):
                return False
        
        return True # probably in the filter

    def resize(self):
        return None
    
    def h1(self, x):
        h = hashlib.md5()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.length
    
    def h2(self, x):
        h = hashlib.sha1()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.length
    
    def h3(self, x):
        h = hashlib.sha224()
        h.update(bytes(x))
        return int(h.hexdigest(), 16) % self.length
    
    def encode(self, element):
        if type(element) == str:
            return bytes(element, 'utf-8')
        else:
            return bytes(element)
