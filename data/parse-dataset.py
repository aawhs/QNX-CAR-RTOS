import csv

dataset_name='dataset.csv'
output_prefix='dataset-'

# Variables that we want split out into their own files
vars_of_interest = ['Fuel_consumption', 'Engine_coolant_temperature', 'Engine_speed', 'Current_Gear', 'Vehicle_speed']

# Need to split the CSV into one file per column
with open(dataset_name, 'r') as f:
    reader = csv.DictReader(f)

    rows = [x for x in reader]
    columns = [x for x in rows[0].keys() if x in vars_of_interest]

print(columns)

for col in columns:
    fname = output_prefix+col+'.txt'
    print('Writing to ', fname)
    with open(fname, 'w', newline='') as f:
        writer = csv.writer(f)
        for row in rows:
            line = [row[col]]
            writer.writerow(line)
