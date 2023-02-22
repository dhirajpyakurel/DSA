

def encode(text):
    alphabets = 'abcdefghijklmnopqrstuvwxyz'
    shift = 15
    encoded_text = ''

    for char in text:
        if char.isalpha():
            # Get the index of the character in the alphabets list
            char_index = alphabets.index(char.lower())
            encoded_index = (char_index + shift) % 26

            # Get the encoded character from the alphabets list and append it to the encoded text
            encoded_text += alphabets[encoded_index] if char.islower() else alphabets[encoded_index].upper()
        else:
            encoded_text += char
    return encoded_text


def decode(text):
    """
    Decode the given ciphertext using the Caesar Cipher method with the given shift.
    """

    alphabets = 'abcdefghijklmnopqrstuvwxyz'
    shift = 15
    decoded = ''

    for char in text:
        if char.isalpha():
            # Get the index of the character in the alphabets list
            char_index = alphabets.index(char.lower())
            encoded_index = (char_index - shift) % 26

            # Get the encoded character from the alphabets list and append it to the decoded text
            decoded += alphabets[encoded_index] if char.islower() else alphabets[encoded_index].upper()
        else:
            decoded += char
    return decoded
