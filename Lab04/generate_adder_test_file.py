f = open('all_pairs_adder_test.txt', 'w')

f.write('A[4] B[4] C[4] Cin Cout\n')

ab_values = range(0, 16)
cin_values = range(0, 1)

for a in ab_values:
    for b in ab_values:
        for cin in cin_values:
            c = (a+b+cin)%16
            if a+b+cin >= 16:
                cout = 1
            else:
                cout = 0
            f.write("{} {} {} {} {}\n".format(a, b, c, cin, cout))
