

def read_from_txt(path):
    """read data from txt, ensure the data format must be :data1, data2

    Args:
        path (the path of the txt file): the path of the txt file

    Returns:
        list: return a list , its elements are also list 
    """
    data = None
    with open(path, 'r', encoding='utf-8') as f:
        data = f.readlines()
    data = [list(eval(item.strip())) for item in data if not item.startswith('#')]
    return data

def convert_data(data):
    # from top left to core
    for item in data:
        item[0] -= 730
        item[1] -= 389
    
    # central symmetry
    for item in data:
        item[1] *= -1
    
    # move
    for item in data:
        item[0] -= 2
        item[1] += 10
    return data

data = read_from_txt('右.txt')
data = convert_data(data)
print(data)