.name		"gloomikon"
.comment	"take it easy"


ld %50, r3
ld %4, r16
ld %0, r2

print:
live %-1
sti r2, %69, r3
add r3, r16, r3
add r8, r8, r8
zjmp %:print

