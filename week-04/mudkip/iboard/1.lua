local function numberToBinStr(x) --https://gist.github.com/lexnewgate/28663fecae78324a87f38aa9c2e0a293
	ret = ""
	while x ~= 1 and x ~= 0 do
		ret = tostring(x%2) .. ret
		x = math.modf(x/2)
	end
	ret = tostring(x) .. ret
	return ret
end

for line in io.lines() do
	p1 = false
	p2 = false
	--print(line)
	for char in line:gmatch(".") do
		dec = string.byte(char)
		bin = numberToBinStr(dec)
		bin_rev = string.reverse(bin)
		if string.len(bin_rev) ~= 7 then bin_rev = bin_rev .. "0" end --HAX
		for bit in bin_rev:gmatch(".") do
			if tonumber(bit) == 1 then
				p1 = not p1
			else
				p2 = not p2
			end
		end
	end
	print((p1 or p2) and "trapped" or "free")
end
