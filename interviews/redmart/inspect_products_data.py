### python 3.5
### pandas
import pandas as pd

# get list of products 
products = pd.read_csv('products.csv', sep=',')

# check if there are any duplicated product ID
products.set_index('product ID').index.get_duplicates()

# find maximum width value
max_width = products['width'].idxmax()
products['width'][max_width]

# find maximum height value
max_height = products['height'].idxmax()
products['height'][max_height]

# find maximum length value
max_length = products['length'].idxmax()
products['length'][max_length]

# check data types of all columns 
print(products.dtypes) 
