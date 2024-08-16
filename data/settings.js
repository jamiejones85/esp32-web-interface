var settings = {

	wifiValidatePasswordLength: function(pw)
	{
		document.getElementById("apsubmit").disabled = pw.length < 8;
	},

	populateSettingsTab: function()
	{
		var settingsTab = document.getElementById("settings");
		var settingsFetchRequest = new XMLHttpRequest();
		settingsFetchRequest.onload = function()
		{
			settingsTab.innerHTML = this.responseText;
		}
		settingsFetchRequest.open("GET", "/settings");
		settingsFetchRequest.send();
	},

}