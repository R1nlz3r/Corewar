.name "zork"
.comment "just a basic living prog"

start:	sti	r1, %:live, %1
		ld %52, r3
		ld %0, r2
		fork %:end
		and %1, %0, r2
		aff r3
		zjmp %:live

live:	live	%1
		and %1, %0, r2
		zjmp %:live

end:	aff r3
		aff r3
