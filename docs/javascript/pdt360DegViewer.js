var
	file_path = '../assets/img_360/Image-',
	file_type = 'jpeg',
	n = 60,
	interval,
	pause = false,
	speed = 85,
	touch = false;

// Load Page and Enable Autoplay
loaderNone();

var i = 1, j = 0, move = [],
	mainDiv = document.querySelector(`#product360`);
	mainDiv.className = 'viewer';
	mainDiv.innerHTML += `<img class="frame" draggable="false" src='${file_path}${i}.${file_type}' title="Scroll Mouse or Drag Image">`;
	mainDiv.innerHTML += '<div class="loader"></div>'

	// Load Images
	for (var k = 1; k <= n; k++) {
			document.getElementById('dummy').innerHTML += `<img src='${file_path}${k}.${file_type}'>`;
	}

var img = document.querySelector(`#product360 .frame`);

(window.matchMedia("screen and (max-width: 992px)").matches) ? touchFun() : nonTouch();


//For Touch Devices
window.addEventListener('touchstart', function () {
	touchFun();
});

function touchFun() {
	touch = true;
	img.removeAttribute('draggable');
	img.addEventListener('touchmove', function (e) {
		logic(this, e);
	});
	img.addEventListener('touchend', function (e) {
		move = [];
	});
}


//For Non-Touch Devices
function nonTouch() {
	touch = false;
	mouseEvent();

	img.addEventListener('mousedown', function (e) {
		drag = true;
		logic(this, e);
	});
	img.addEventListener('mouseup', function (e) {
			drag = false;
			move = [];
	});

	img.addEventListener('wheel', function (e) {
		// Pause on Scroll
		pause = true;
		
		// Index Scrolling
		e.preventDefault();
		(e.wheelDelta / 120 > 0) ? nxt(this) : prev(this);
	});

	function mouseEvent() {
		img.addEventListener('mousemove', function (e) {
			(drag) ? logic(this, e) : null;
		});
	}
}


// Iterate through frames
function logic(el, e) {
	pause = true;
	j++;
	var x = touch ? e.touches[0].clientX : e.clientX;
	var coord = (x - img.offsetLeft);
	move.push(coord);

	var l = move.length,
		oldMove = move[l - 2],
		newMove = move[l - 1];
	var thresh = touch ? true : !(j % 3);
	if (thresh) {
		if (newMove > oldMove)
			prev(el);
		else if (newMove < oldMove)
			nxt(el);
	}
}

function prev(e) {
	if (i <= 1) {
		i = n;
		e.src = `${file_path}${--i}.${file_type}`;
		nxt(e);
	} else
		e.src = `${file_path}${--i}.${file_type}`;
}

function nxt(e) {
	if (i >= n) {
		i = 1;
		e.src = `${file_path}${++i}.${file_type}`;
		prev(e);
	} else
		e.src = `${file_path}${++i}.${file_type}`;
}


// Page Loading
function autoplay() {
	clearInterval(interval);
	interval = setInterval(function () {
		if (!pause) {
			nxt(img);
		}
	}, speed);
}

function loaderNone() {
	window.addEventListener('load',function(){
		document.querySelector(`.loader`).style.display = 'none';
		pause = false;
		autoplay();
	});
}
