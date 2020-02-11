local c = io.read()
local t, b, l, r = c, c, c, c
for line in io.lines() do
	tc, bc, lc, rc = line:match("(%d)(%d)(%d)(%d)")
	t = t - tc
	b = b - bc
	l = l - lc
	r = r - rc
end

local count = 0

while t+b >= 2 and l+r >= 2 do	
	for i=1,2 do
		if t ~= 0 then
			t = t - 1
		elseif b ~= 0 then
			b = b - 1
		end

		if l ~= 0 then
			l = l - 1
		elseif r ~= 0 then
			r = r - 1
		end
	end
	count = count + 1
end
print(count .. " " .. math.floor(t+b) .. " " .. math.floor(l+r))
