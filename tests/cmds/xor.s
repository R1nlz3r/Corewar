.name "xor"
.comment "S(RG/ID/D4), S(RG/ID/D4), D(RG)"

xor r1, r1, r1
xor r1, 1, r1
xor r1, %1, r1

xor 1, r1, r1
xor 1, 1, r1
xor 1, %1, r1

xor %1, r1, r1
xor %1, 1, r1
xor %1, %1, r1
