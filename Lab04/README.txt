The ALU cannot properly calculate in the following case:

- Arithmetic Shift Right fails in some case, which the circuit will shift positive values with the negative signing bit.
- Not equal circuit is malfunctioning due to the lack of one NOT gate.
- Less than (lt) fails to check for the minimum and maximum value of signed integer, resulting in two errors.
- Greater than (gt) fails in the same case.
