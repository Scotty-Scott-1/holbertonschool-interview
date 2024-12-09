#!/usr/bin/node

const request = require('request');
const arg = process.argv[2];
let array = [];

request('https://swapi-api.hbtn.io/api/films/' + arg , (error, response, body) => {

	if(error) {
		console.log('error: ', error);
	} else {
		const data = JSON.parse(body);
		const film_characters = data.characters;

		const charpromise = film_characters.map(url => {
			return new Promise((resolve, reject) => {
				request(url, (error, response, body) => {
					const data2 = JSON.parse(body);
					resolve(data2.name);

				});
			});
		});
		Promise.all(charpromise).then(names => {array = names;
			array.forEach(name => {
				console.log(name);
			})
		});
	}

});

