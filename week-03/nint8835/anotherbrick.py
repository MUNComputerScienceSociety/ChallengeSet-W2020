print(
    (
        __import__(
            list.__name__[2] + type.__name__[1] + list.__name__[2]
        ).setrecursionlimit(100000000),
        (
            lambda _, __: (lambda ___, *____: ___(___, *____))(
                lambda _____, ______, _______, ________: type.__name__[1].upper()
                + type.__name__[3].upper()
                + str.__name__[0].upper()
                if _______ > _
                else int.__name__[1].upper() + object.__name__[0].upper()
                if len(________) == 0 or ________[0] > ______
                else _____(
                    _____,
                    ______ - ________[0] if ______ != ________[0] else __,
                    _______ + 1 if ______ == ________[0] else _______,
                    ________[1:],
                ),
                __,
                1,
                [int(_________) for _________ in input().split()],
            )
        )(*[int(__________) for __________ in input().split()][:-1]),
    )[-1]
)

