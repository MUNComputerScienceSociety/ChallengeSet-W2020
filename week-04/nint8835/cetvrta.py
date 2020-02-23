print(
    *(
        lambda _, __, ___: (
            lambda ____, _____: (
                lambda ______, _______: (
                    _______([________[_] for ________ in ______]),
                    _______([________[__] for ________ in ______]),
                )
            )(
                [
                    tuple(map(int, _________.split()))
                    for _________ in ____.stdin.read().split(_____.whitespace[___])[
                        : _ - __
                    ]
                ],
                lambda __________: next(
                    ___________
                    for ___________ in __________
                    if __________.count(___________) == __
                ),
            )
        )(
            __import__(str.__name__[_] + type.__name__[__] + str.__name__[_]),
            __import__(str.__name__ + int.__name__[: _ - __] + globals.__name__[_]),
        )
    )(*map(len, [[], [...], [..., ...]]))
)
