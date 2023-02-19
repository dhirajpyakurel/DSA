//defines a Class Called Queue


class Queue {


  //this constructor take an argument
  constructor(limit) {
    this.queue = [];// empty array
    this.limit = limit; // this provides the limit 
  }


  //this is used to add an element at the end of the queue
  enqueue(data) {
    if (this.queue.length >= this.limit) {


      // if the length is greater then or equal to the limit then it automatically removes the first element that was inserted in the queue
      this.dequeue();
    }
    //if not then it pushes the data in the queue
    this.queue.push(data);
  }



  //this helps to remove the first element that was inserted in the queue
  dequeue() {
    if (this.queue.length > 0) {
      this.queue.shift();
    }
  }


  // this will return the queue array

  getQueue() {
    return this.queue;
  }

  //this will return the most recent cutomer that is added to the queue. if the queue is empty then the return data will be null
  getLatestCustomer() {
    if (this.queue.length > 0) {
      return this.queue[this.queue.length - 1];
    } else {
      return null;
    }
  }


  //this method will calculate the averaget wait time for all the customers in the querue.
  getAverageWaitTime() {
    let sum = 0;//First we have initialized the sum to zero
    for (let i = 0; i < this.queue.length; i++) {


      //then this loop will iterate over each customer to add thier wait time to the sum  and the average wait time is calaculated and returned

      sum += this.queue[i].waitTime;
    }
    return (sum / this.queue.length).toFixed(2);
  }
}

const waitlistQueue = new Queue(10);// we have intialized an new queue


// These keywords are used to insert and get the data from the html file

const addButton = document.querySelector('.add-button');
const nameInput = document.querySelector('.name-input');
const estimateTime = document.getElementById('estimate-time');
const waitlist = document.getElementById('waitlist');
const dequeueButton = document.querySelector('.dequeue-button');


//when the button is clicked then it takes the entered name from the input field and if the input is empty then it creates an alert asking the user to enter the name, if the input is not empty then it creates an new customer object which will store the user name , its time the customer has been aded and the wait time which will initially be zero. Then it enqueues the customer basically an enqueue() method is called. HERE THE Update waittlist is called which will update the displayed waitlist


addButton.addEventListener('click', () => {
  let name = nameInput.value;

  if (name === '') {
    alert('Please enter a name!');
  } else {
    alert(`Added ${name} to waitlist!`);
    const customer = {
      name: name,
      timestamp: new Date(),
      waitTime: null
    };
    waitlistQueue.enqueue(customer);
    updateWaitlist();
  }
});

// this element reads the button click and calls the dequeue method from the class and deques the first element that was inserted


dequeueButton.addEventListener('click', () => {
  waitlistQueue.dequeue();
  updateWaitlist();
});


function updateWaitlist() {
  const tableBody = document.querySelector('#waitlist');//selects the element from the HTML,having the waitlist ID
  tableBody.innerHTML = '';//clears the content 

  if (waitlistQueue.getQueue().length > 0) {// this check if there are any customers 
    const queueItems = waitlistQueue.getQueue();//Assign an Array of customers in the queue

    for (let i = queueItems.length - 1; i >= 0; i--) {
      //this loop helps to iterate over the array of customers in reverse order
      const customer = queueItems[i];
      const tableRow = document.createElement('tr');

      const tableName = document.createElement('td');
      tableName.innerText = customer.name;

      const tableTimestamp = document.createElement('td');
      tableTimestamp.innerText = customer.timestamp.toLocaleTimeString();

      const now = new Date();

      //creates an object and assign it to the variable now 
      const waitTime = customer.waitTime ?? 0;// while creating an object the waitime inside an customer object is set to null and if it is NULL thne it will return 0;

      //this line assigns the wait time of the current customers to a variable called waitTime. ?? coalescing
      const elapsed = (now - customer.timestamp) / 1000 / 60;//calculates the elapsed time for the cutomer ,
      const totalWaitTime = waitTime + Math.max(elapsed - waitTime, 0);

      const tableWaitTime = document.createElement('td');//creates another row element for the table 
      tableWaitTime.innerText = `${totalWaitTime.toFixed(2)} minutes`;// and stores the waittime that is calculated

      tableRow.appendChild(tableName);
      tableRow.appendChild(tableTimestamp);
      tableRow.appendChild(tableWaitTime);

      tableBody.appendChild(tableRow);
    }

    const latestCustomer = waitlistQueue.getLatestCustomer();
    if (latestCustomer !== null) {
      const now = new Date();
      const minutes = Math.floor((now - latestCustomer.timestamp) / 60000);
      latestCustomer.waitTime = minutes;
      estimateTime.innerText = `${waitlistQueue.getAverageWaitTime().toFixed(2)} minutes`;
    }
  } else {
    estimateTime.innerText = '0 minutes';
  }
}
