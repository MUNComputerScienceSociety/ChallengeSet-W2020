local x, y, c1, c2, our_x, our_y = {}, {}

for input in io.lines() do
	c1, c2 = input:match("(%d+) (%d+)")
	x[c1] = (x[c1] or 0) + 1
	y[c2] = (y[c2] or 0) + 1
end

for k, v in pairs(x) do
	if v ~= 2 then
		our_x = k
		break
	end
end

for k, v in pairs(y) do
	if v ~= 2 then
		our_y = k
		break
	end
end

print(our_x .. " " .. our_y)
