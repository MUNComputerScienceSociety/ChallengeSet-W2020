print(
    (
        lambda _: (
            lambda __, ___: (
                lambda ____: _.whitespace[2].join(
                    [
                        callable.__name__[:2].capitalize()
                        + set.__name__[:-1]
                        + _.whitespace[0]
                        + str(_____ + 1)
                        + _.punctuation[15]
                        + _.whitespace[0]
                        + UnicodeError.__name__[:3].upper()
                        + _.ascii_uppercase[16]
                        + super.__name__[1].upper()
                        + super.__name__[3].upper()
                        if ______.split()[0] not in ____
                        else callable.__name__[:2].capitalize()
                        + set.__name__[:-1]
                        + _.whitespace[0]
                        + str(_____ + 1)
                        + _.punctuation[15]
                        + _.whitespace[0]
                        + ____[______.split()[0]]
                        + _.whitespace[0]
                        + ______.split()[1]
                        for _____, ______ in enumerate(
                            ___.stdin.read().split(_.whitespace[2])[:-1]
                        )
                    ]
                )
            )({**__, **{________: _______ for _______, ________ in __.items()}})
        )(
            {
                abs.__name__[0].upper()
                + _.punctuation[2]: (bool.__name__[0] * 2).capitalize(),
                callable.__name__[0].upper()
                + _.punctuation[2]: dict.__name__[0].upper()
                + bin.__name__[0],
                delattr.__name__[0].upper()
                + _.punctuation[2]: enumerate.__name__[0].upper()
                + bytearray.__name__[0],
                filter.__name__[0].upper()
                + _.punctuation[2]: globals.__name__[0].upper()
                + globals.__name__[3],
                getattr.__name__[0].upper()
                + _.punctuation[2]: abs.__name__[:-1].capitalize(),
            },
            __import__(str.__name__[0] + type.__name__[1] + str.__name__[0]),
        )
    )(__import__(str.__name__ + int.__name__[:-1] + globals.__name__[0]))
)
