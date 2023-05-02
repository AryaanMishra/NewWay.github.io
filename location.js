const findLocation = () => {

    const status = document.querySelector('.status');

    const success = (position) =>{
        console.log(position)
        const latitude = position.coords.latitude;
        const longitude = position.coords.longitude;
        console.log(latitude + ' ' + longitude)

        const geoApiUrl = `https://api.bigdatacloud.net/data/reverse-geocode-client?latitude=${latitude}&longitude=${longitude}&localityLanguage=en`

        fetch(geoApiUrl)
        .then(res => res.json())
        .then(data =>{
            status.textContent = "Weather In " + data.locality
            
        })
        const options = {
            method: 'GET',
            headers: {
                'X-RapidAPI-Key': 'a9e627b264msh1d35ff57697fdafp1bf6b9jsn31b5b68cde73',
                'X-RapidAPI-Host': 'open-weather13.p.rapidapi.com'
            }
        };
        const weat = 'https://open-weather13.p.rapidapi.com/city/merced'
        fetch(weat, options)
            .then(response => response.json())
            .then(response => console.log(response))
    //         .then(data =>   {
    //             temp.textContent = data.main.temp
    //         })
     }
    const error = () => {
        status.textContent = 'unable to retrieve your location';
    }
    navigator.geolocation.getCurrentPosition(success, error);


    
    
    

}

document.querySelector('.your_Location').addEventListener('click',findLocation);
