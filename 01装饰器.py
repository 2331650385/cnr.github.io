def outer(fn):
    def inner(*args, **kwargs):
        return f"结果是:{fn(*args, **kwargs)}"

    return inner


@outer  # add = outer(add)
def add(a, b):
    return a + b


print(add(10, 20))

@outer
def reduce(a, b, c):
    return a - b - c

print(reduce(10, 20,-10))
