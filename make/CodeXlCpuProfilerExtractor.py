'''
Created on Dec 19, 2017

@author: dws
'''
import csv
import getopt
import os
import re
import sys
from _ast import arg

def main(argv):
    input_csv_folder = None
    output_csv = None
    try:
        opts, args = getopt.getopt(argv,"hi:o:")
    except:
        print('CodeXlCpuProfilerExtractor.py -i <input csv folder path> -o <output csv path>')
        sys.exit(2)
        
    for opt, arg in opts:
        if opt == '-h':
            print('CodeXlCpuProfilerExtractor.py -i <input csv folder path> -o <output csv path>')
            sys.exit()
        elif opt in ("-i"):
            input_csv_folder = arg
        elif opt in ("-o"):
            output_csv = arg
            
    if not input_csv_folder or not output_csv:
        print('CodeXlCpuProfilerExtractor.py -i <input csv folder path> -o <output csv path>')
        sys.exit(2)
        
    # Get all of the .csv file names.
    csv_files = [filename for filename in os.listdir(input_csv_folder) if filename.endswith(".csv")]
        
    # This dictionary will use a format like this: Filename: Duration
    # It will then be used to create an output .csv file where the column headers
    # are the filenames and the values are the duration times.
    collected_data = {}
    
    # Loop through all of the csv files found in the input folder.
    for input_csv_filename in csv_files:
        duration = None
        input_csv_filepath = input_csv_folder + '/' + input_csv_filename
        with open(input_csv_filepath) as f:
            reader = csv.reader(f)
    
            # Loop through each row in the current csv file to locate the data we care about.
            for row in reader:
                # Looking for the Profile Duration value.
                if 'Profile Duration:' in row:
                    duration = row
                    break
        
            if duration:
                # Trying to extract the Profile Duration value.
                # Expecting the string to look like this: ['Profile Duration:', '74 seconds']
                duration_time = re.search("^.*', '([0-9]+).*$", str(duration))

                if duration_time:
                    # Remove .csv from the filename of the current csv file.
                    filename = os.path.splitext(input_csv_filename)[0]
                    # Add the current filename as a key in the dictionary with the duration time
                    # as its value.
                    collected_data[filename] = duration_time.group(1)
            else:
                sys.exit("Profile Duration was not found in the input .csv.  No output .csv was created.")
    
    if collected_data:
        # Write the output .csv file.
        fieldnames = []            
        with open(output_csv, 'w', newline='') as csvfile:
            for key, value in collected_data.items():
                fieldnames.append(key)
                
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
                
            writer.writerow(collected_data)    

if __name__ == "__main__":
    main(sys.argv[1:])