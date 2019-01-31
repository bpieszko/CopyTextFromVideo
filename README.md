# CopyTextFromVideo

## Description
Mutlithreaded script to copy text from video file or camera. It is based on Tesseract OCR and OpenCV libraries.

## Dependencies
```
OpenCV
Tesseract
C++ in version at least 14
```
## Building
```
cd CopyTextFromVideo
mkdir build
cd build
cmake ..
make
```

## Using
```
./CopyTextFromVideo -v [file path or 0 to capture from camera] 2> /dev/null
```

## Example
```
./CopyTextFromVideo -v video.mp4 2> /dev/null
```

## Author
Bartosz Pieszko<br/>
bartosz.pieszko@gmail.com

## Example usage results
### Input
[![Video file not found](https://img.youtube.com/vi/x5QmQ27Md1E/0.jpg)](https://www.youtube.com/watch?v=x5QmQ27Md1E)
### Usage
```
./CopyTextFromVideo -v file_from_youtube.mp4 2> /dev/null
```
### Output
```
[Intro: Future]
Shorty, shorty uh
Shorty
Tsunami Warning
I got mars, 40 on me

Take your time, shorty (time)
Dont even worry, shorty (don't even worry)
Study around shorty (study around)
Bust that shit down shorty (bust that shit down)
You ain't go down for shorty (ain't go down)
Shorty

Told her, gone need me shorty
Molly on me shorty
Cant feel my teeth shorty, New car no keys
Gucci on my fleece, shorty
You ain't hittin’ no stain with me, then no,
you ain't gone eat, shorty
Thats on an L&B, shorty
Thats who I be, shorty, yeah
Fill up the Bag fill up the bag fill up the
bag, make

Pullin’ up with your hoe, I might put her on the back of my
jetski
Money be causing me to change on niggas
Money be causing me to change on bitches
The money will change a nigga
We treat the money like its a religion
Convicted to the hood, malicious for the hood
Finnessin' for the hood, came from nothing out the mud

Pour the cups up with [?] shorty
This money ain't enough for shorty
I pass the gun to my shorty, ahh
He shoot that shit at your shorty, ahh
I'm a Chicago baby
Where we get bloody and gory, ahh

Rest is audio! :)
Like and
subscribe!
```
