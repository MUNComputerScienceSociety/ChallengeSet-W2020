import sys

code = sys.stdin.read()

PREAMBLE = """import sys

tape = [0 for i in range(30000)]
head = 0

"""

TOKENS = {
    ">": "head += 1",
    "<": "head -= 1",
    "+": "tape[head] += 1",
    "-": "tape[head] -= 1",
    ".": "print(chr(tape[head]), end='')",
}


def parse_code(start, end, indent_count=0):
    program = ""
    current_pos = start
    while current_pos < end:
        char = code[current_pos]

        if char in TOKENS:
            program += " " * indent_count + TOKENS[char] + "\n"
        elif char == ",":
            program += " " * indent_count + "val = sys.stdin.read(1)\n"
            program += (
                " " * indent_count + "tape[head] = ord(val) if len(val) == 1 else 0\n"
            )
        elif char == "[":
            end_pos = current_pos
            bracket_count = 1
            while bracket_count > 0:
                end_pos += 1
                if end_pos >= len(code):
                    raise SyntaxError("Missing matching bracket")
                if code[end_pos] == "[":
                    bracket_count += 1
                elif code[end_pos] == "]":
                    bracket_count -= 1
            parsed_code = parse_code(current_pos + 1, end_pos + 1, indent_count + 4)
            program += (
                " " * indent_count
                + "while tape[head] != 0:\n"
                + (
                    parsed_code
                    if len(parsed_code) > 0
                    else " " * (indent_count + 4) + "pass\n"
                )
            )
            current_pos = end_pos
        current_pos += 1

    return program


with open("out.py", "w", encoding="utf8") as f:
    f.write(PREAMBLE + parse_code(0, len(code)))
