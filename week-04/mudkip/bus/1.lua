local c = io.read() -- lmao don't even need this crap >_<
for n in io.lines() do
	q = 0
	while n~=0 do
		q = 2*(q + 0.5)
		n = n - 1
	end
	print(math.floor(q))
end
