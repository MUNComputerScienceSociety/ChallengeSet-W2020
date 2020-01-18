print(
    "\n".join(
        (
            lambda _: [
                "{0:.3f}%".format((len(___) / len(_[__])) * 100)
                for __, ___ in enumerate(
                    [
                        [
                            ____
                            for ____ in ________
                            if ____
                            > [sum(______) / len(______) for ______ in _][_______]
                        ]
                        for _______, ________ in enumerate(_)
                    ]
                )
            ]
        )(
            [
                [int(_________) for _________ in input().split()][1:]
                for __________ in range(int(input()))
            ]
        )
    )
)
