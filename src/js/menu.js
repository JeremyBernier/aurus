//get node webkit GUI
var gui = require('nw.gui');

// get the window object
var win = gui.Window.get();
var menubar = new gui.Menu({
    type: 'menubar'
});

var file = new gui.Menu();
var subMenu = new gui.Menu();

file.append(new gui.MenuItem({
    label: 'New',
    click: function() {
        alert('Action 1 Clicked');
    }
}));
file.append(new gui.MenuItem({type: 'separator'}));
file.append(new gui.MenuItem({
    label: 'Open',
    click: function() {
        alert('Action 2 Clicked');
    }
}));
subMenu.append(new gui.MenuItem({
    label: 'Recent joint 1',
    click: function() {
        alert('SubMenu Action 1 Clicked');
    }
}));

subMenu.append(new gui.MenuItem({
    label: 'Recent joint 2',
    click: function() {
        alert('SubMenu Action 2 Clicked');
    }
}));
file.append(new gui.MenuItem({ label: 'Open Recent', submenu: subMenu}));
file.append(new gui.MenuItem({
    label: 'Close',
    click: function() {
        alert('Action 2 Clicked');
    }
}));
file.append(new gui.MenuItem({type: 'separator'}));
file.append(new gui.MenuItem({
    label: 'Exit',
    click: function() {
        alert('Action 2 Clicked');
    }
}));

var help = new gui.Menu();
help.append(new gui.MenuItem({
	label: 'Help'
}));
help.append(new gui.MenuItem({
	label: 'About',
	click: function() {
		window.open('about.html', '_blank', 'screenX=0,screenY=0,width=100,height=100');
	}
}));

menubar.append(new gui.MenuItem({ label: 'File', submenu: file}));
menubar.append(new gui.MenuItem({ label: 'Help', submenu: help}));

win.menu = menubar;