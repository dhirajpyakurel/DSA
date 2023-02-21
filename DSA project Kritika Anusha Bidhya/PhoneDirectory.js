// get elements from the DOM (access element from html)
const nameInput = document.getElementById('name');
const phoneInput = document.getElementById('phone');
const addButton = document.getElementById('add');
const contactsList = document.getElementById('contacts');

// create an array to hold contacts
let contacts = [];

// function to render(give) contacts on the page
function fContacts() {
  
  contactsList.innerHTML = '';// clear the contacts list <<innerHTML (to access or modify html contents)

  // loop through the contacts array and create an li element for each contact
  for (let i = 0; i < contacts.length; i++) 
  {
    
    const contact = contacts[i];

    const li = document.createElement('li');
    li.innerText = `${contact.name}: ${contact.phone}`;

    const deleteButton = document.createElement('button');
    deleteButton.innerText = 'Delete';
    deleteButton.classList.add('delete');
    deleteButton.addEventListener('click', () => {
      // remove the contact from the array
      contacts.splice(i, 1);
      // re-render the contacts
      fContacts();
    });

    li.appendChild(deleteButton);
    contactsList.appendChild(li);
  }
}

// function to add a new contact
function addContact() {
  const name = nameInput.value;
  const phone = phoneInput.value;

  // create a new contact object and add it to the contacts array
  const contact = { name, phone };
  contacts.push(contact);

  // clear the input fields
  nameInput.value = '';
  phoneInput.value = '';

  // re-render the contacts
  fContacts();
}

// add event listener to the Add button
addButton.addEventListener('click', addContact);

// render the contacts on page load
fContacts();


function fContacts() {
  // sort the contacts array in ascending order
  for (let i = 1; i < contacts.length; i++) {
    let j = i - 1;
    const temp = contacts[i];
    while (j >= 0 && contacts[j].name > temp.name) {
      contacts[j + 1] = contacts[j];
      j--;
    }
    contacts[j + 1] = temp;
  }

  // clear the contacts list
  contactsList.innerHTML = '';

  // loop through the sorted contacts array and create an li element for each contact
  for (let i = 0; i < contacts.length; i++) {
    const contact = contacts[i];

    const li = document.createElement('li');
    li.innerText = `${contact.name}: ${contact.phone}`;

    const deleteButton = document.createElement('button');
    deleteButton.innerText = 'Delete';
    deleteButton.classList.add('delete');
    deleteButton.addEventListener('click', () => {
      // remove the contact from the array
      contacts.splice(i, 1);
      // re-render the contacts
      fContacts();
    });

    li.appendChild(deleteButton);
    contactsList.appendChild(li);
  }
}

