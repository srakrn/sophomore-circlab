def to_signed_bit(x):
    return format(x & 0xff, '08b')

f = open('all_inputs_sra_test.txt', 'w')
f.write('A[8] shft[3] out[8]\n')

a_values = range(-128, 128)
shft_values = range(0, 8)

for a in a_values:
    for shft in shft_values:
        out = a >> shft
        print("{} {}".format(a, to_signed_bit(a)))
        f.write("{} {} {}\n".format(to_signed_bit(a), shft, to_signed_bit(out)))
