.name "zork"
.comment "just a basic living prog"

l2:	sti	r1,%:live,%1
	ld %0, r2
	ld %4, r3
	and	r1,%0,r4
live:	live	%1
	sti r1, r2, %:end
	add r2, r3, r2
	and	r1,%0,r4
	zjmp	%:live
end:
