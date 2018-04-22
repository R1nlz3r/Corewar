.name "ldi"
.comment "S(RG/ID/D2), S(D2/RG), D(RG)"

ldi r1, %1, r1
ldi r1, r1, r1

ldi 1, %1, r1
ldi 1, r1, r1

ldi %1, %1, r1
ldi %1, r1, r1
