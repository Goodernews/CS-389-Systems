import pandas as pd
import numpy as np

df = pd.read_csv("Output.csv")

if len(df.columns)==3:
    df.pivot(index= "Trial", columns='Size (Bytes)', values='Time (NS)').to_csv("Output.csv")
