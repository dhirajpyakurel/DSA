import json


def delete_hw(source_dict: dict, subject: str, id, button_index) -> None:
    
    """deletes a key with provided id from source dictionary"""
    deleted_elem = source_dict['homework'].pop(subject, )
    print(button_index)
    
    pass
