from filter import Filter

x = Filter(10000, 3)
x.insert('123')
print(x.query('123'))
print(x.query('12'))