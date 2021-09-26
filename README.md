# AETHER
##Smart home environmental sensing
##Split into two parts: a hardware/firmware side and a software side
##Hardware collects data from environmental sensors, such as temp/humidity, air quality sensors, etc
##Does any pre/processing if necessary, then packages the data as a JSON object and pushes it to an ##external db
##On the software side, a Discord bot will be pulling the data and push notifications
##That's more or less the idea
##It could be extended by having some kind of web app showing the data. Might be interesting to do some ##kind of data analysis