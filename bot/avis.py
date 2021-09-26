##aetherbot
import discord
import json
import asyncio
import os

from settings import TOKEN

##add the thing to connect to database later here
client=discord.Client()

##event to be called on when bot starts being used
@client.event
async def on_ready():
    print('logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.startswith('.hello'):
        await message.channel.send('hey!')

##make this work later
@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.startswith('.intro'):
        await message.channel.send('hey! my name is Aether, your AErometric Tethered Home Responder.')

client.run(TOKEN)