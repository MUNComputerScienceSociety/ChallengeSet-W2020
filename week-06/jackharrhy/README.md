Tested using: `gcc (Arch Linux 9.2.1+20200130-2) 9.2.1 20200130`

build:

```bash
make all # builds both non-threaded and threaded
```

run:

```bash
make sample{1,2,3,{1,2,3}-threads}
```

---

Entry count | Reason                 | Status
------------|------------------------|--------
1 entry     | Correct solution       | ✅
2 entries   | In CS2004              | ✅
3 entries   | Solution in C          | ✅
4 entries   | Multithreaded solution | ✅

Total: 1 + 2 + 3 + 4 = _10 entries_
