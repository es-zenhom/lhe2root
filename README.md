
# LHE to ROOT Conversion and Analysis

This repository contains a C++ script, `lhe_analysis.C`, which is part of a larger project focused on the conversion and analysis of data from high energy physics experiments. This script specifically deals with the analysis of data in the Les Houches Event (LHE) format.

## Project Context

The `lhe_analysis.C` script is a component of a larger suite of tools and scripts used in the analysis of data from high-energy physics experiments. The overarching goal of these experiments is to better understand the fundamental particles and forces of the universe.

In this context, the script plays a crucial role in analyzing the data that has been converted from the LHE format to the ROOT format. The LHE format is a common format for event files in high-energy physics, while ROOT is a data analysis framework developed by CERN.

## Script Functionality

The script reads data from a ROOT file, which is a standard file format in high-energy physics research. It then applies a series of operations to the data, selecting only those events that meet specific criteria. In this case, the script is specifically interested in the transverse momentum of leptons.

The script is built on the ROOT data analysis framework, a comprehensive system for large-scale data analysis developed by CERN. ROOT provides a wide array of functionalities, including statistical analysis, data visualization, and data storage.

## Usage

To use this script, you need to have the ROOT framework installed on your system. You can then run the script on your data file using the following command:

```bash
root -l lhe_analysis.C
```

Please note that this script is part of a larger data analysis pipeline and may require specific data formats and structures to function correctly. It is recommended to have a solid understanding of the data and the overall project context before using this script.

## About the Author

The script is developed by Eslam Zenhom, a data analyst with a background in high-energy physics. With experience in data analysis, statistical modeling, and programming, I am skilled in transforming complex data into meaningful insights. [Your Name] has a deep understanding of the ROOT framework and the data structures used in high-energy physics, and has applied this knowledge in the development of this script and others like it.

