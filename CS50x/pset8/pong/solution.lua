--all code that was not added or edited was removed
--this will not work without the rest of the code
--which can be found in the cs50 2020 game track 

function love.update(dt)
    -- player 2 movement
    if ball.x > VIRTUAL_WIDTH/2 then
        if ball.y < player2.y - 3 then
            player2.dy = -PADDLE_SPEED/1.5
        elseif ball.y > player2.y + 3 then
            player2.dy = PADDLE_SPEED/1.5
        else
            player2.dy = 0
        end
    end

    player2:update(dt)
end