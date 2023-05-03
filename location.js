const findLocation = () => {

    const status = document.querySelector('.status');

    const success = (position) =>{
        console.log(position)
        const latitude = position.coords.latitude;
        const longitude = position.coords.longitude;
        console.log(latitude + ' ' + longitude)

        // const geoApiUrl = `https://api.bigdatacloud.net/data/reverse-geocode-client?latitude=${latitude}&longitude=${longitude}&localityLanguage=en`
        // const geoApiUrl = `https://maps.googleapis.com/maps/api/geocode/json?latlng=${latitude},${longitude}&key=YourApiKey`
        const geoApiUrl = `https://nominatim.openstreetmap.org/reverse?format=jsonv2&lat=${latitude}&lon=${longitude}`
        // const geoApiUrl = `https://nominatim.openstreetmap.org/reverse?format=geojson&lat=${latitude}&lon=${longitude}`
        fetch(geoApiUrl)
        .then(res => res.json())
        .then(data =>{
            status.textContent = "Weather In " + data.display_name
            
        })
       
    }
    const error = () => {
        status.textContent = 'unable to retrieve your location';
    }
    navigator.geolocation.getCurrentPosition(success, error);


    
    
    

}

document.querySelector('.your_Location').addEventListener('click',findLocation);
