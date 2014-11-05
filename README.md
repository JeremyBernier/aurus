Making an open source DAW. 

Note: It's not even close to finished yet. I'm just uploading it in its premature state so that other people can see and potentially contribute.

Main Goals:
* Modular. Audio engine decoupled from GUI.
* Cross-Platform (Linux, Windows, Mac)
* Not shitty

Other: 
* JACK is utilized for audio.

Potential features:
* Ability to compose entire track within one piano roll
* 3D

For the GUI, I'm making the initial prototype with Node-Webkit (aka HTML5/CSS3/Javascript). The reason being that (1) it's really easy to customize and re-style (2) it's quick to develop in (3) I already know how to code web apps and have no experience with QT, GTK+, Java GUIs outside of Swing, etc.

Motivation:
I've tried pretty much every mainstream DAW, and none of them feel like home to me. Audio editing in FL Studio sucks and the piano roll in Ableton Live sucks. I have a ton of ideas on UI improvements that I'd love to see implemented, but there's nothing I can do about it because their code is closed-source.

Ultimately, DAWs should be completely customizable and cater to each user. Every musician has their own preferences, so a 1-size-fits all package is not good enough. 

Of course there are already open source DAWs. I'm still in the process of investigating them, and will probably borrow code to avoid wasting time reinventing the wheel.
