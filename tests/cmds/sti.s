.name "sti"
.comment "S(RG), S(RG/ID/D2), S(D2/RG)"

sti r1, r1, %1
sti r1, 1, %1
sti r1, %1, %1

sti r1, r1, r1
sti r1, 1, r1
sti r1, %1, r1
