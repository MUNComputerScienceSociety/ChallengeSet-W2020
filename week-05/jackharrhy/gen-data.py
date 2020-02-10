import json
from itertools import permutations

with open("../../problems/10mins/10mins.json") as json_file:
    data = json.load(json_file)
    locations = data.keys()
    perms = list(permutations(locations, 2))
    for index, perm in enumerate(perms):
        with open(f"./test-data/{index}.in", "x") as f:
            f.write(f"{perm[0]}\n{perm[1]}\n")
