.name "lldi"
.comment "S(RG/ID/D2), S(D2/RG), D(RG)"

lldi r1, %1, r1
lldi r1, r1, r1

lldi 1, %1, r1
lldi 1, r1, r1

lldi %1, %1, r1
lldi %1, r1, r1
