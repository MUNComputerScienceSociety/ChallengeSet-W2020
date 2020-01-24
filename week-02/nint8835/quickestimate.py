print(
    (lambda _: _(10).join([str(len(input())) for __ in range(int(input()))]))(
        lambda *___: str().join(map(chr, ___))
    )
)
