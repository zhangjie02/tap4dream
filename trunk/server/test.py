r = [(1, 10000),
    (1, 5226),
    (3, 2371),
    (5, 1401),
    (5, 783),
    (5, 587),
    (5, 440),
    (5, 357),
    (8, 293),
    (8, 220),
    (24, 171)
    ]

start = 1
total_w = 0
for (n, w) in r:
    total_w += n * w

for (n, w) in r:
    print 'start:%d %f %f' % (start, w*1000.0 / total_w, n*w*1000.0/total_w)

    # if n == 1:
    #     print start
    # else:
    #     print start, start + n -1

    start += n

# div = 10000
# for (n, w) in r:
#     a = w *1.0/ div
#     print a
#     div = w

PRIZE = [(1, 200),
            (1, 100),
            (3, 50),
            (5, 30),
            (5, 16),
            (5, 12),
            (5, 9),
            (5, 7),
            (8, 6),
            (8, 4.5),
            (24, 3.5),
            (40, 2)
            ]

ret = []
for n, w in PRIZE:
    ret.append({'count':n, 'weight': w})
print ret