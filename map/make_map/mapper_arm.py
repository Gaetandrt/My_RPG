#!/usr/bin/env python3
import json
import sys

def main():
    to_exclude = 0
    with open(sys.argv[1]) as f:
        content = f.read()
    obj = json.loads(content)
    for i in range(len(obj["layers"][1]["data"])) :
        print("1" if obj["layers"][1]["data"][i] != to_exclude else "0", end= '')
        if (i + 1) % obj["height"] == 0 and i != 0 :
            print("")
main()