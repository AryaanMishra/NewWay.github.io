function submitForm(event) {
    event.preventDefault();
  
    // Get the form data
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const message = document.getElementById("message").value;
  
    // Validate the form data
    if (!name || !email || !message) {
      alert("Please fill in all fields");
      return;
    }
  
    // Send the form data to the server
    const formData = { name, email, message };
    fetch("/submit-form", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(formData),
    })
      .then((response) => response.json())
      .then((data) => {
        console.log(data);
        document.getElementById("name").value = "";
        document.getElementById("email").value = "";
        document.getElementById("message").value = "";
        document.getElementById("success-message").style.display = "block";
      })
      .catch((error) => {
        console.error(error);
        alert("An error occurred, please try again later.");
      });
  }
  