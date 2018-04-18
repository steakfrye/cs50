from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    #open file a
    a = open(file1, "r")
    #check that file is readable
    if a.mode == r:
        #store lines in variable
        a_lines = a.readlines()
        #create set
        a_set = set()
        #store lines in set
        for i in range len(a_lines):
            a_set.add(a_lines[i])

    #open file b
    b = open(file2, "r")
    if b.mode == r:
        #store lines in variable
        b_lines = b.readlines()
        #create set
        b_set = set()
        #store lines in set
        for j in range len(b_lines):
            b_set.add(b_lines[j])

    #compare list a with list b
    compared_list = set(a_set).intersection(b_set)

    a.close()
    b.close()
    return compared_list


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    # Take in string inputs a, b
    # Split each string into sentences
    # Compute list of all sentences in a and b
    # Avoid duplicates
    # Return list of matches

    return []


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    # Take in string inputs a, b, and substring length n
    # Split each string into all substrings of length n
    # Compute list of all substrings in a and b
    # Return list of matches

    #get user input n
    #Create helper function
    #iterate through each string's character of length n
    #while n does not reach end of string (string[n:])
    #compare a and b
    #compile list

    #return list
    return []
