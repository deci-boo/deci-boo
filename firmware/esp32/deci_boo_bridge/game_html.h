// AUTO-GENERATED from web/game.html by tools/embed_html.py — do not edit by hand.
#pragma once
static const char GAME_HTML[] PROGMEM = R"DECIBOO(
<!DOCTYPE html>
<html lang="th">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Deci-Boo! Roar Games</title>
<style>
:root{
  --bg:#07080c; --ink:#f1ead0; --mute:#9a9681; --amber:#ffcf5a;
  --p1:#46d36a; --p2:#ff5a4d; --card:#14161d; --line:#262a35;
}
*{box-sizing:border-box}
html,body{margin:0;height:100%}
body{background:radial-gradient(ellipse at 50% -10%,#1d2230 0%,var(--bg) 60%);color:var(--ink);
  font-family:system-ui,-apple-system,"Segoe UI",Tahoma,sans-serif;min-height:100vh;overflow-x:hidden}
button{font:inherit;cursor:pointer}
.hidden{display:none!important}
.title{font-family:Impact,"Arial Black",system-ui,sans-serif;letter-spacing:.04em;margin:0}

/* ---------- sprites ---------- */
.spr{position:relative;width:100%}
.spr svg{display:block;width:100%;height:auto;overflow:visible}
.spr .mo,.spr .ba,.spr .arm-r{display:none}
.spr.roar .mo,.spr.roar .ba,.spr.roar .arm-r{display:inline}
.spr.roar .mc,.spr.roar .bi,.spr.roar .arm-i{display:none}
.spr .rig{transform-origin:100px 212px;animation:bob 2.6s ease-in-out infinite}
.spr.roar .rig{animation:shake .08s linear infinite}
.spr.sad .rig{animation:none;transform:scale(1,.93);filter:grayscale(.7) brightness(.75)}
.spr.sad .iris{transform:translateY(4px)}
@keyframes bob{50%{transform:translateY(-4px) scale(1.01,.99)}}
@keyframes shake{0%{transform:translate(-2px,0) scale(1.07)}50%{transform:translate(2px,-2px) scale(1.09)}100%{transform:translate(-2px,1px) scale(1.07)}}
.spr::before,.spr::after{content:"";position:absolute;left:50%;top:58%;width:60%;aspect-ratio:1;border-radius:50%;
  border:4px solid var(--amber);transform:translate(-50%,-50%) scale(.3);opacity:0;pointer-events:none}
.spr.roar::before{animation:ring .7s ease-out infinite}
.spr.roar::after{animation:ring .7s ease-out .35s infinite}
@keyframes ring{0%{opacity:.9;transform:translate(-50%,-50%) scale(.4)}100%{opacity:0;transform:translate(-50%,-50%) scale(1.9)}}
.roartag{position:absolute;top:-6%;left:50%;transform:translateX(-50%) rotate(-6deg);font:900 clamp(14px,2.2vw,26px) Impact,"Arial Black",sans-serif;
  color:var(--amber);text-shadow:0 0 12px #ff8a00,2px 2px 0 #000;opacity:0;white-space:nowrap;pointer-events:none}
.spr.roar .roartag{opacity:1;animation:tag .25s ease-in-out infinite alternate}
@keyframes tag{to{transform:translateX(-50%) rotate(4deg) scale(1.12)}}

/* ---------- select screen ---------- */
#select{max-width:1100px;margin:0 auto;padding:28px 16px 40px;text-align:center}
#select h1{font-size:clamp(40px,8vw,84px);color:var(--amber);text-shadow:0 0 24px rgba(255,170,0,.45),4px 4px 0 #3b1d00;line-height:1}
#select h1 small{display:block;font-size:.38em;color:var(--ink);letter-spacing:.3em;text-shadow:none;margin-top:6px}
.lede{color:var(--mute);margin:14px 0 24px}
.pick-head{display:grid;grid-template-columns:1fr auto 1fr;gap:18px;align-items:center;margin-bottom:14px}
.vs{align-self:center;font:900 54px Impact,sans-serif;color:var(--amber);text-shadow:0 0 18px #ff9d00}
.pslot{background:var(--card);border:2px solid var(--line);border-radius:16px;padding:12px 14px;transition:.2s}
.pslot h2{font-size:24px;margin:0 0 8px}
.pslot[data-p="0"] h2{color:var(--p1)} .pslot[data-p="1"] h2{color:var(--p2)}
.pslot[data-p="0"].turn{border-color:var(--p1);box-shadow:0 0 24px rgba(70,211,106,.3)}
.pslot[data-p="1"].turn{border-color:var(--p2);box-shadow:0 0 24px rgba(255,90,77,.3)}
.pslot b{display:block;font:900 20px Impact,sans-serif;letter-spacing:.06em;margin-top:8px;color:var(--mute)}
.pslot input{width:100%;padding:9px 12px;border-radius:10px;border:1px solid var(--line);background:#0c0e13;color:var(--ink);font-size:15px}
.pick-box{background:var(--card);border:1px solid var(--line);border-radius:18px;padding:16px}
.pick-prompt{font:900 26px Impact,"Arial Black",sans-serif;letter-spacing:.04em;margin-bottom:12px}
.pick-box .ghost{margin-top:12px}
.cards{display:grid;grid-template-columns:repeat(4,1fr);gap:12px}
.mcard{position:relative;background:#0e1016;border:3px solid var(--line);border-radius:14px;padding:10px 8px 8px;color:var(--ink);transition:.15s}
.mcard:hover:not(:disabled),.mcard:focus-visible{border-color:#5a6072;transform:translateY(-2px)}
.mcard .badge{position:absolute;top:8px;left:8px;font:900 14px Impact,sans-serif;padding:2px 9px;border-radius:999px;color:#0b0b0b;display:none}
.mcard.by0{border-color:var(--p1);box-shadow:0 0 0 3px rgba(70,211,106,.25),0 0 24px rgba(70,211,106,.3)}
.mcard.by1{border-color:var(--p2);box-shadow:0 0 0 3px rgba(255,90,77,.25),0 0 24px rgba(255,90,77,.3)}
.mcard.by0 .badge{display:block;background:var(--p1)}.mcard.by1 .badge{display:block;background:var(--p2)}
.mcard.by0:disabled,.mcard.by1:disabled{opacity:1;cursor:default}
.mcard .spr{width:78%;margin:6px auto 0}
.mcard b{display:block;font:900 20px Impact,sans-serif;letter-spacing:.06em;margin-top:2px}
.mcard span{display:block;font-size:12px;color:var(--mute);min-height:2.4em}
.mcard:disabled{opacity:.3;cursor:not-allowed}
.settings{display:flex;gap:18px;justify-content:center;flex-wrap:wrap;margin:22px 0}
.settings label{display:flex;gap:8px;align-items:center;color:var(--mute)}
select{background:#0c0e13;color:var(--ink);border:1px solid var(--line);border-radius:8px;padding:7px 10px;font-size:15px}
.big-btn{font:900 26px Impact,"Arial Black",sans-serif;letter-spacing:.08em;padding:14px 46px;border:0;border-radius:14px;
  background:linear-gradient(#ffd864,#f2a400);color:#2b1700;box-shadow:0 6px 0 #9a5d00,0 0 30px rgba(255,180,0,.35)}
.big-btn:active{transform:translateY(3px);box-shadow:0 3px 0 #9a5d00}
.big-btn:disabled{filter:grayscale(1);opacity:.5;cursor:not-allowed}

/* ---------- game screen ---------- */
#game{max-width:1400px;margin:0 auto;padding:12px 16px 32px}
.hud{display:flex;justify-content:space-between;align-items:center;gap:10px;flex-wrap:wrap;margin-bottom:10px}
.hud .title{font-size:28px;color:var(--amber)}
.hud-mid{font-weight:700;font-size:17px}
.hud-mid .who{padding:3px 10px;border-radius:999px;margin-left:6px}
.pill{font-size:12px;padding:5px 11px;border-radius:999px;background:#2a2e3a;white-space:nowrap}
.pill.ok{background:#123d22;color:#86efac}.pill.sim{background:#3d2e10;color:#ffd27a}
.ghost{background:transparent;border:1px solid var(--line);color:var(--mute);border-radius:8px;padding:5px 10px;font-size:13px}

.arena{display:grid;grid-template-columns:minmax(80px,180px) minmax(0,1fr) minmax(80px,180px);gap:12px;align-items:end}
.side{text-align:center;transition:.3s;opacity:.55}
.side.active{opacity:1}
.side .spr{filter:drop-shadow(0 8px 14px rgba(0,0,0,.6))}
.side.active .spot{background:radial-gradient(ellipse at 50% 85%,rgba(255,220,120,.28),transparent 65%)}
.spot{padding:24px 4px 0;border-radius:16px}
.side .pname{font:900 18px Impact,sans-serif;letter-spacing:.06em;margin-top:6px}
.side[data-p="0"] .pname{color:var(--p1)}.side[data-p="1"] .pname{color:var(--p2)}

.board{position:relative;container-type:inline-size;aspect-ratio:16/10;border-radius:14px;overflow:hidden;
  background:radial-gradient(ellipse at 50% 25%,#2b302b 0%,#121412 55%,#050606 100%);
  box-shadow:0 20px 50px rgba(0,0,0,.6),inset 0 0 0 1px #2a2d2a;
  display:grid;grid-template-columns:1fr .78fr 1fr;gap:1.6cqw;padding:5cqw 3.2cqw 11cqw}
.board::before{content:"";position:absolute;inset:0 0 auto 0;height:5cqw;
  background:repeating-linear-gradient(90deg,transparent 0 9cqw,#3b3f3b 9cqw 9.25cqw);opacity:.7}
.truss{position:absolute;left:0;right:0;bottom:0;height:9cqw;border-top:.8cqw solid #2c3034;
  background:repeating-linear-gradient(60deg,transparent 0 2.6cqw,#2f3438 2.6cqw 3.1cqw),
  repeating-linear-gradient(-60deg,transparent 0 2.6cqw,#2f3438 2.6cqw 3.1cqw),linear-gradient(#141719,#08090a)}
.truss::after{content:"";position:absolute;left:0;right:0;top:3.4cqw;height:.6cqw;background:#2c3034}

.panel{position:relative;z-index:1;border-radius:1.2cqw;padding:1.6cqw 1.6cqw 1.2cqw;display:flex;flex-direction:column;
  box-shadow:inset 0 0 3cqw rgba(0,0,0,.65),0 1cqw 2cqw rgba(0,0,0,.5)}
.panel.left{background:linear-gradient(165deg,#5c7a40,#2a3b1f 75%);border:.35cqw solid #1a2612}
.panel.right{background:linear-gradient(195deg,#7a3434,#381515 75%);border:.35cqw solid #250d0d}
.plate{background:linear-gradient(#4a4524,#2f2b14);border:.3cqw solid #8d823c;border-radius:.7cqw;text-align:center;
  padding:.7cqw .5cqw;margin-bottom:1.2cqw;font:900 max(11px,3.3cqw) Impact,"Arial Black",sans-serif;letter-spacing:.12em;
  color:#ffe7a3;text-shadow:0 0 1.2cqw #ffb300;white-space:nowrap;overflow:hidden;text-overflow:ellipsis}
.rows{flex:1;display:flex;flex-direction:column;justify-content:space-around}
.row{display:grid;grid-template-columns:2.2cqw 1fr 4.6cqw;align-items:center;gap:.8cqw;
  font:italic 800 max(8px,1.9cqw) system-ui,sans-serif;color:#c9c39a;transition:opacity .3s}
.panel.right .row{grid-template-columns:4.6cqw 1fr 2.2cqw}
.panel.right .row em{order:3}.panel.right .row .pts{order:1;text-align:left}.panel.right .row .seg{order:2}
.row em{font-style:italic;opacity:.85}
.row .pts{text-align:right;font-style:normal;font-size:max(8px,1.6cqw);color:#ffe7a3}
.row.dim{opacity:.22}
.row.fail .pts{color:#ff7b6b}
.row.cur .seg{outline:.25cqw solid var(--amber);outline-offset:.25cqw;animation:curb 1s ease-in-out infinite}
@keyframes curb{50%{outline-color:transparent}}
.seg{position:relative;height:2.1cqw;border-radius:.35cqw;overflow:hidden;
  background:repeating-linear-gradient(90deg,#2d2b21 0 .55cqw,#141310 .55cqw .8cqw)}
.segfill{position:absolute;top:0;bottom:0;left:0;width:0;transition:width .9s cubic-bezier(.2,.8,.2,1);
  background:repeating-linear-gradient(90deg,#fff6cf 0 .55cqw,transparent .55cqw .8cqw);filter:drop-shadow(0 0 .5cqw #ffcf5a)}
.panel.right .segfill{left:auto;right:0}

.center{position:relative;z-index:1;display:flex;flex-direction:column;align-items:center;justify-content:flex-end;gap:1.2cqw}
.tubes{flex:1;display:flex;gap:2cqw;align-items:stretch;min-height:0}
.tube{display:flex;flex-direction:column;align-items:center;gap:.5cqw}
.tube .tl{font:900 max(8px,1.6cqw) Impact,sans-serif;letter-spacing:.1em}
.tube:first-child .tl{color:var(--p1)}.tube:last-child .tl{color:var(--p2)}
.house{flex:1;width:8.6cqw;border-radius:2cqw 2cqw .8cqw .8cqw;padding:1.6cqw 2.3cqw 1.2cqw;
  background:linear-gradient(90deg,#b9ae7d,#f3ebc6 38%,#d8cd9c 70%,#a99d6b);box-shadow:0 .6cqw 1.6cqw rgba(0,0,0,.6),inset 0 .4cqw 0 #fff8dc}
.slot{position:relative;height:100%;border-radius:.4cqw;overflow:hidden;
  background:repeating-linear-gradient(to top,#3b1512 0 .6cqw,#110807 .6cqw .9cqw)}
.fill{position:absolute;left:0;right:0;bottom:0;height:0;transition:height 1.1s cubic-bezier(.2,.8,.2,1);
  background:repeating-linear-gradient(to top,#ff4a36 0 .6cqw,transparent .6cqw .9cqw);filter:drop-shadow(0 0 .7cqw #ff2a14)}
.tube .tot{font:900 max(10px,2.4cqw) Impact,sans-serif;color:#ffe7a3;text-shadow:0 0 1cqw #ffb300;min-width:6cqw;text-align:center}
.lights{display:flex;gap:1.6cqw;background:linear-gradient(#1a1d20,#0b0c0d);padding:1cqw 1.8cqw;border-radius:1.2cqw;border:.25cqw solid #2e3236}
.lamp{display:block;width:5.4cqw;aspect-ratio:1;border-radius:50%;border:.3cqw solid #050505;transition:background .25s,box-shadow .25s}
.lamp.g{background:radial-gradient(circle at 35% 30%,#2c4a2c,#0d1a0d)}
.lamp.y{background:radial-gradient(circle at 35% 30%,#4a4224,#1a160b)}
.lamp.r{background:radial-gradient(circle at 35% 30%,#4a2424,#1a0b0b)}
.lamp.g.on{background:radial-gradient(circle at 35% 30%,#d6ffd6,#3bea4a 45%,#0f8a1a);box-shadow:0 0 3cqw #3bea4a,0 0 7cqw rgba(59,234,74,.5)}
.lamp.y.on{background:radial-gradient(circle at 35% 30%,#fff7cf,#ffc21a 45%,#a46d00);box-shadow:0 0 3cqw #ffc21a,0 0 7cqw rgba(255,194,26,.5)}
.lamp.r.on{background:radial-gradient(circle at 35% 30%,#ffd6d0,#ff3b2a 45%,#8a0f05);box-shadow:0 0 3cqw #ff3b2a,0 0 7cqw rgba(255,59,42,.5)}
.lamp.r.on.blink{animation:lblink .5s steps(1) infinite}
@keyframes lblink{50%{background:radial-gradient(circle at 35% 30%,#4a2424,#1a0b0b);box-shadow:none}}
.lamp.fade{transition:background 3s linear,box-shadow 3s linear}

#bigmsg{position:absolute;z-index:5;left:50%;top:44%;transform:translate(-50%,-50%);text-align:center;pointer-events:none;
  background:rgba(5,6,8,.72);backdrop-filter:blur(3px);border:.25cqw solid rgba(255,207,90,.35);border-radius:2cqw;
  padding:1.6cqw 4cqw;min-width:30cqw}
#bigmsg .t{font:900 max(22px,7cqw) Impact,"Arial Black",sans-serif;letter-spacing:.06em;color:var(--amber);text-shadow:0 0 2cqw #ff8a00;line-height:1}
#bigmsg .s{font-size:max(11px,1.8cqw);color:var(--ink);margin-top:.6cqw}
#bigmsg .pbar{height:1cqw;background:#2a2d33;border-radius:1cqw;overflow:hidden;margin-top:1cqw}
#bigmsg .pbar i{display:block;height:100%;width:100%;background:var(--amber);transform-origin:left}
#bigmsg.pop .t{animation:pop .45s ease-out}
@keyframes pop{0%{transform:scale(1.8);opacity:0}100%{transform:scale(1);opacity:1}}
#bigmsg.pass .t{color:#5dff74;text-shadow:0 0 2cqw #1fd13b}
#bigmsg.fail .t{color:#ff6a5a;text-shadow:0 0 2cqw #ff2a14}

.controls{display:grid;grid-template-columns:1.1fr 1.3fr 1fr;gap:12px;margin-top:14px}
.card{background:var(--card);border:1px solid var(--line);border-radius:14px;padding:14px 16px}
.card h3{margin:0 0 8px;font-size:13px;font-weight:600;color:var(--mute);letter-spacing:.04em;text-transform:uppercase}
.thv{font:900 44px Impact,sans-serif;color:var(--amber);line-height:1}
.thv small{font:600 13px system-ui;color:var(--mute);margin-left:6px}
input[type=range]{width:100%;accent-color:var(--amber);margin:10px 0 6px}
.presets{display:flex;gap:6px;flex-wrap:wrap}
.presets button{flex:1;min-width:52px;padding:6px 0;border-radius:8px;border:1px solid var(--line);background:#0e1016;color:var(--ink);font-size:13px}
.presets button:disabled,input:disabled{opacity:.4;cursor:not-allowed}
.hint{font-size:12px;color:var(--mute);margin-top:8px;line-height:1.5}
.mbar{position:relative;height:26px;border-radius:8px;background:#0b0c10;border:1px solid var(--line);overflow:hidden}
.mfill{position:absolute;inset:0 auto 0 0;width:0;background:linear-gradient(90deg,#2dd4bf,#facc15 60%,#ef4444);transition:width .08s}
.mth{position:absolute;top:-2px;bottom:-2px;width:3px;background:#fff;box-shadow:0 0 8px #fff}
.mpk{position:absolute;top:0;bottom:0;width:2px;background:#ff7ab6;opacity:0}
.mrow{display:flex;justify-content:space-between;font-size:13px;color:var(--mute);margin-top:6px}
.mrow b{color:var(--ink)}
.go-row{display:flex;gap:8px;margin-top:12px;align-items:center;flex-wrap:wrap}
.go-row .big-btn{font-size:20px;padding:10px 26px;flex:1}
.simbtn{padding:10px 14px;border-radius:12px;border:1px dashed #8a6a1a;background:#221a08;color:#ffd27a;font-weight:700;user-select:none;touch-action:none}
.simbtn.held{background:#5a3e06}
.res-line{display:flex;justify-content:space-between;font-size:14px;padding:3px 0;border-bottom:1px dashed #262a35}
.res-line:last-child{border:0}
.res-line b{font-variant-numeric:tabular-nums}
.res-total{font:900 30px Impact,sans-serif;margin-top:6px}
.res-total.ok{color:#5dff74}.res-total.bad{color:#ff6a5a}
details.rules{margin-top:12px}
details.rules summary{cursor:pointer;color:var(--mute)}
details.rules .card{margin-top:8px;line-height:1.7;font-size:14px}
code{background:#0b0c10;padding:1px 6px;border-radius:5px;font-size:13px}

/* ---------- end modal ---------- */
.modal{position:fixed;inset:0;z-index:20;background:rgba(0,0,0,.72);display:grid;place-items:center;padding:16px}
.modal .box{background:var(--card);border:1px solid var(--line);border-radius:20px;padding:24px;text-align:center;max-width:440px;width:100%}
.modal .spr{width:56%;margin:20px auto 0}
.modal h2{font:900 40px Impact,sans-serif;color:var(--amber);margin:8px 0 4px}
.modal p{color:var(--mute);margin:0 0 18px}
.modal .btns{display:flex;gap:10px;justify-content:center;flex-wrap:wrap}
.modal .big-btn{font-size:20px;padding:10px 22px}

@media (max-width:860px){
  .controls{grid-template-columns:1fr}
}
@media (max-width:720px){
  .pick-head{grid-template-columns:1fr auto 1fr;gap:8px}
  .cards{grid-template-columns:repeat(2,1fr)}
  .vs{font-size:28px}
  .arena{grid-template-columns:1fr 1fr;grid-template-areas:"b b" "s1 s2"}
  .arena .board{grid-area:b}.arena .side[data-p="0"]{grid-area:s1}.arena .side[data-p="1"]{grid-area:s2}
  .side .spr{max-width:120px;margin:0 auto}
}
</style>
</head>
<body>

<!-- ======================= SELECT ======================= -->
<section id="select">
  <h1 class="title">DECI-BOO!<small>ROAR GAMES</small></h1>
  <p class="lede">มาดูกันว่าใครคำรามได้ดังและนานกว่า</p>
  <div class="pick-head">
    <div class="pslot" data-p="0"><h2 class="title">PLAYER 1</h2><input id="pn0" maxlength="14" placeholder="ชื่อผู้เล่น 1"><b id="pick0">ยังไม่เลือก</b></div>
    <div class="vs">VS</div>
    <div class="pslot" data-p="1"><h2 class="title">PLAYER 2</h2><input id="pn1" maxlength="14" placeholder="ชื่อผู้เล่น 2"><b id="pick1">ยังไม่เลือก</b></div>
  </div>
  <div class="pick-box">
    <div class="pick-prompt" id="pickPrompt"></div>
    <div class="cards" id="cards"></div>
    <button class="ghost" id="repick">เลือกใหม่</button>
  </div>
  <div class="settings">
    <label>จำนวนรอบต่อคน
      <select id="optRounds"><option>1</option><option>2</option><option selected>3</option><option>4</option><option>5</option><option>6</option></select>
    </label>
    <label>เวลาคำราม
      <select id="optRoar"><option value="2000">2 วิ</option><option value="3000" selected>3 วิ</option><option value="4000">4 วิ</option></select>
    </label>
  </div>
  <button class="big-btn" id="startGame" disabled>เริ่มเกม!</button>
  <p class="hint" id="selConn"></p>
</section>

<!-- ======================= GAME ======================= -->
<main id="game" class="hidden">
  <div class="hud">
    <h1 class="title">DECI-BOO!</h1>
    <div class="hud-mid" id="hudTurn"></div>
    <div style="display:flex;gap:8px;align-items:center">
      <span class="pill" id="conn">…</span>
      <button class="ghost" id="quit">ออก</button>
    </div>
  </div>

  <div class="arena">
    <div class="side" data-p="0"><div class="spot"><div class="spr" id="spr0"></div></div><div class="pname" id="sname0"></div></div>

    <div class="board">
      <div class="truss"></div>
      <div class="panel left"><div class="plate" id="plate0">P1</div><div class="rows" id="rows0"></div></div>
      <div class="center">
        <div class="tubes">
          <div class="tube"><span class="tl">P1</span><div class="house"><div class="slot"><div class="fill" id="fill0"></div></div></div><span class="tot" id="tot0">0</span></div>
          <div class="tube"><span class="tl">P2</span><div class="house"><div class="slot"><div class="fill" id="fill1"></div></div></div><span class="tot" id="tot1">0</span></div>
        </div>
        <div class="lights"><i class="lamp g" id="lampG"></i><i class="lamp y" id="lampY"></i><i class="lamp r" id="lampR"></i></div>
      </div>
      <div class="panel right"><div class="plate" id="plate1">P2</div><div class="rows" id="rows1"></div></div>
      <div id="bigmsg" class="hidden"><div class="t"></div><div class="s"></div><div class="pbar hidden"><i></i></div></div>
    </div>

    <div class="side" data-p="1"><div class="spot"><div class="spr" id="spr1"></div></div><div class="pname" id="sname1"></div></div>
  </div>

  <section class="controls">
    <div class="card">
      <h3>Threshold ตานี้</h3>
      <div class="thv"><span id="thv">2000</span><small>/ 4000</small></div>
      <input type="range" id="th" min="100" max="4000" step="25" value="2000">
      <div class="presets" id="presets">
        <button data-v="1000">1000</button><button data-v="2000">2000</button><button data-v="2800">2800</button><button data-v="3500">3500</button>
      </div>
      <div class="hint">ตั้งสูง = คะแนนฐานเยอะ แต่เสี่ยงคำรามไม่ถึง · หมุน KY-040 ปรับได้เหมือนกัน</div>
    </div>
    <div class="card">
      <h3>เสียงสด (KY-037 peak-to-peak)</h3>
      <div class="mbar"><div class="mfill" id="mfill"></div><div class="mpk" id="mpk"></div><div class="mth" id="mth"></div></div>
      <div class="mrow"><span>amp <b id="ampv">0</b></span><span>peak ตานี้ <b id="pkv">–</b></span><span>เกินเกณฑ์ <b id="holdv">–</b></span></div>
      <div class="go-row">
        <button class="big-btn" id="go">เริ่มตานี้</button>
        <button class="simbtn hidden" id="simRoar">กดค้าง = จำลองเสียง</button>
      </div>
      <div class="hint" id="goHint">หรือกดปุ่มบน KY-040</div>
    </div>
    <div class="card" id="lastCard">
      <h3>ผลตาล่าสุด</h3>
      <div id="lastRes" class="hint">ยังไม่มีผล</div>
    </div>
  </section>

  <details class="rules">
    <summary>กติกา &amp; สูตรคิดคะแนน</summary>
    <div class="card">
      <b>ลำดับต่อตา:</b> ไฟเหลือง = เตรียมตัว (ตั้ง threshold) → กดเริ่ม ไฟเหลืองค่อยๆ ดับใน 3 วิ → <b>ROAR!</b> คำรามใส่ไมค์ → ไฟ<span style="color:#5dff74">เขียว</span> = ผ่าน / ไฟ<span style="color:#ff6a5a">แดง</span> = ไม่ผ่าน<br>
      <b>ผ่านเมื่อ:</b> peak ≥ threshold <i>และ</i> ดังเกินเกณฑ์รวมกัน ≥ 0.2 วิ (กันตบมือ/เคาะไมค์)<br>
      <b>คะแนน</b> = <code>threshold ÷ 10</code> (ความกล้า) + <code>(peak − threshold) ÷ 20</code> (ดังเกิน) + <code>สัดส่วนเวลาที่ดังเกิน × 100</code> (ความอึด)<br>
      ไม่ผ่าน = 0 คะแนน · ครบทุกรอบ หลอดกลางใครสูงกว่าชนะ
    </div>
  </details>
</main>

<div class="modal hidden" id="end">
  <div class="box">
    <div class="spr" id="sprWin"></div>
    <h2 id="winTitle"></h2>
    <p id="winSub"></p>
    <div class="btns">
      <button class="big-btn" id="again">เล่นอีกครั้ง</button>
      <button class="ghost" id="reselect">เลือกตัวใหม่</button>
    </div>
  </div>
</div>

<script>
/* =========================================================
   Sprites (original monsters, inline SVG, idle + roar poses)
   ========================================================= */
const OUT = '#24121c';
const lim = (d, c, w) => `<path d="${d}" fill="none" stroke="${OUT}" stroke-width="${w + 5}" stroke-linecap="round"/><path d="${d}" fill="none" stroke="${c}" stroke-width="${w}" stroke-linecap="round"/>`;
function eye(cx, cy, r, iris, side) {
  const t = cy - r - 5;
  const ang = side === 0
    ? `M${cx - r} ${t - 9} L${cx} ${t + 3} L${cx + r} ${t - 9}`
    : side < 0 ? `M${cx - r} ${t - 10} L${cx + r} ${t + 2}` : `M${cx - r} ${t + 2} L${cx + r} ${t - 10}`;
  return `<circle cx="${cx}" cy="${cy}" r="${r}" fill="#fff" stroke="${OUT}" stroke-width="3"/>
  <g class="iris"><circle cx="${cx}" cy="${cy + r * .1}" r="${r * .52}" fill="${iris}"/><circle cx="${cx}" cy="${cy + r * .1}" r="${r * .24}" fill="#0b0b0b"/>
  <circle cx="${cx - r * .22}" cy="${cy - r * .18}" r="${r * .15}" fill="#fff"/></g>
  <path class="bi" d="M${cx - r} ${t} Q${cx} ${t - 8} ${cx + r} ${t}" fill="none" stroke="${OUT}" stroke-width="4" stroke-linecap="round"/>
  <path class="ba" d="${ang}" fill="none" stroke="${OUT}" stroke-width="5" stroke-linecap="round" stroke-linejoin="round"/>`;
}
function mouth(cx, cy, w, h) {
  const x0 = cx - w / 2, x1 = cx + w / 2, n = 5, tw = w / n;
  let top = '', bot = '';
  for (let i = 0; i < n; i++) {
    const a = x0 + tw * i;
    top += `<path d="M${a + 1} ${cy - 1} L${a + tw / 2} ${cy + h * .5} L${a + tw - 1} ${cy - 1} Z" fill="#fffbe8" stroke="${OUT}" stroke-width="1.5"/>`;
  }
  for (let i = 1; i < n - 1; i++) {
    const xm = x0 + tw * i + tw / 2, k = (xm - cx) / (w / 2), yb = cy + h * 1.15 * (1 - k * k);
    bot += `<path d="M${xm - tw / 2.4} ${yb} L${xm} ${yb - h * .42} L${xm + tw / 2.4} ${yb} Z" fill="#fffbe8" stroke="${OUT}" stroke-width="1.5"/>`;
  }
  return `<g class="mc"><path d="M${x0 + 6} ${cy} Q${cx} ${cy + h * .7} ${x1 - 6} ${cy}" fill="none" stroke="${OUT}" stroke-width="4" stroke-linecap="round"/>
    <path d="M${cx - w * .22} ${cy + h * .2} l4 9 l4 -8" fill="#fffbe8" stroke="${OUT}" stroke-width="1.5"/><path d="M${cx + w * .22 - 8} ${cy + h * .2} l4 9 l4 -9" fill="#fffbe8" stroke="${OUT}" stroke-width="1.5"/></g>
  <g class="mo"><path d="M${x0} ${cy - 2} Q${cx} ${cy - h * .4} ${x1} ${cy - 2} Q${cx} ${cy + h * 2.3} ${x0} ${cy - 2} Z" fill="#3a0a16" stroke="${OUT}" stroke-width="3.5"/>
    <ellipse cx="${cx}" cy="${cy + h * .85}" rx="${w * .22}" ry="${h * .3}" fill="#ff5a7a"/>${top}${bot}</g>`;
}
function fur(cx, cy, rx, ry, n, a) {
  let p = [];
  for (let i = 0; i < n * 2; i++) {
    const t = Math.PI * i / n, rr = i % 2 ? 1 : 1 + a / Math.min(rx, ry);
    p.push((cx + Math.cos(t) * rx * rr).toFixed(1) + ',' + (cy + Math.sin(t) * ry * rr).toFixed(1));
  }
  return p.join(' ');
}
const shadow = `<ellipse cx="100" cy="212" rx="62" ry="7" fill="rgba(0,0,0,.4)"/>`;
const MONS = [
  { id: 'gobbo', name: 'GOBBO', tag: 'ตาเดียว เสียงแหลมทะลุหู', color: '#9ae04a', draw: () => {
    const c = '#9ae04a', d = '#6cb52f';
    return `${shadow}<g class="rig">
      <rect x="70" y="176" width="18" height="30" rx="7" fill="${d}" stroke="${OUT}" stroke-width="3"/><rect x="112" y="176" width="18" height="30" rx="7" fill="${d}" stroke="${OUT}" stroke-width="3"/>
      <ellipse cx="77" cy="207" rx="16" ry="7" fill="${d}" stroke="${OUT}" stroke-width="3"/><ellipse cx="123" cy="207" rx="16" ry="7" fill="${d}" stroke="${OUT}" stroke-width="3"/>
      <g class="arm-i">${lim('M38 128 Q16 150 24 178', c, 9)}${lim('M162 128 Q184 150 176 178', c, 9)}</g>
      <g class="arm-r">${lim('M38 118 Q8 104 16 66', c, 9)}${lim('M162 118 Q192 104 184 66', c, 9)}</g>
      <path d="M58 82 L48 40 L76 66 Z" fill="#f3ead0" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <path d="M100 58 L100 24 L114 56 Z" fill="#f3ead0" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <path d="M142 82 L152 40 L124 66 Z" fill="#f3ead0" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <circle cx="100" cy="124" r="70" fill="${c}" stroke="${OUT}" stroke-width="4"/>
      <circle cx="54" cy="148" r="7" fill="${d}"/><circle cx="148" cy="138" r="5" fill="${d}"/><circle cx="132" cy="176" r="6" fill="${d}"/><circle cx="66" cy="176" r="4" fill="${d}"/>
      <ellipse cx="70" cy="86" rx="17" ry="9" fill="#fff" opacity=".28" transform="rotate(-35 70 86)"/>
      ${eye(100, 104, 28, '#1fa37a', 0)}${mouth(100, 150, 64, 22)}</g>`;
  }},
  { id: 'bruto', name: 'BRUTO', tag: 'ขนฟู คำรามสะเทือนพื้น', color: '#8b6ce6', draw: () => {
    const c = '#7b5cd6', l = '#a58cf0';
    return `${shadow}<g class="rig">
      <polygon points="${fur(78, 196, 16, 14, 7, 5)}" fill="${c}" stroke="${OUT}" stroke-width="3"/><polygon points="${fur(122, 196, 16, 14, 7, 5)}" fill="${c}" stroke="${OUT}" stroke-width="3"/>
      <g class="arm-i">${lim('M40 120 Q18 148 30 186', c, 16)}${lim('M160 120 Q182 148 170 186', c, 16)}</g>
      <g class="arm-r">${lim('M40 112 Q6 96 14 58', c, 16)}${lim('M160 112 Q194 96 186 58', c, 16)}
        <path d="M6 58 l4 -10 M14 54 l2 -12 M22 58 l0 -10 M178 58 l0 -10 M186 54 l-2 -12 M194 58 l-4 -10" stroke="#f3ead0" stroke-width="4" stroke-linecap="round"/></g>
      <path d="M62 64 Q28 58 32 26 Q40 42 56 44 Q70 46 74 58 Z" fill="#f3ead0" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <path d="M138 64 Q172 58 168 26 Q160 42 144 44 Q130 46 126 58 Z" fill="#f3ead0" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <polygon points="${fur(100, 122, 70, 76, 30, 7)}" fill="${c}" stroke="${OUT}" stroke-width="4" stroke-linejoin="round"/>
      <ellipse cx="100" cy="156" rx="42" ry="36" fill="${l}" opacity=".85"/>
      <circle cx="56" cy="110" r="6" fill="#5f43b8"/><circle cx="148" cy="124" r="8" fill="#5f43b8"/><circle cx="140" cy="88" r="4" fill="#5f43b8"/>
      ${eye(80, 96, 13, '#f5b301', -1)}${eye(120, 96, 13, '#f5b301', 1)}${mouth(100, 134, 82, 26)}</g>`;
  }},
  { id: 'fang', name: 'FANG', tag: 'หนามแหลม สามตาจ้องเขม็ง', color: '#ff8a3d', draw: () => {
    const c = '#ff8a3d', d = '#e2661c';
    return `${shadow}<g class="rig">
      <path d="M38 118 L46 74 L62 98 L72 52 L88 86 L100 36 L112 86 L128 52 L138 98 L154 74 L162 118 Z" fill="#ffd23f" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <rect x="72" y="178" width="16" height="28" rx="6" fill="${d}" stroke="${OUT}" stroke-width="3"/><rect x="112" y="178" width="16" height="28" rx="6" fill="${d}" stroke="${OUT}" stroke-width="3"/>
      <path d="M62 208 l6 -8 l6 8 l6 -8 l6 8 Z M108 208 l6 -8 l6 8 l6 -8 l6 8 Z" fill="${d}" stroke="${OUT}" stroke-width="3" stroke-linejoin="round"/>
      <g class="arm-i">${lim('M42 136 Q24 156 34 182', c, 9)}${lim('M158 136 Q176 156 166 182', c, 9)}</g>
      <g class="arm-r">${lim('M42 126 Q14 116 22 80', c, 9)}${lim('M158 126 Q186 116 178 80', c, 9)}</g>
      <ellipse cx="100" cy="132" rx="62" ry="68" fill="${c}" stroke="${OUT}" stroke-width="4"/>
      <path d="M70 176 Q100 186 130 176 M76 190 Q100 198 124 190" stroke="${d}" stroke-width="4" fill="none" stroke-linecap="round"/>
      <ellipse cx="72" cy="88" rx="14" ry="8" fill="#fff" opacity=".3" transform="rotate(-30 72 88)"/>
      ${eye(74, 106, 11, '#6a2bd9', -1)}${eye(100, 90, 14, '#6a2bd9', 0)}${eye(126, 106, 11, '#6a2bd9', 1)}${mouth(100, 150, 64, 22)}</g>`;
  }},
  { id: 'wisp', name: 'WISP', tag: 'หนวดดุ๊กดิ๊ก แต่ร้องลั่นห้อง', color: '#ff5fa2', draw: () => {
    const c = '#ff5fa2', d = '#d63d82';
    return `${shadow}<g class="rig">
      <path d="M82 62 Q76 40 64 30" stroke="${OUT}" stroke-width="4" fill="none"/><circle cx="62" cy="28" r="8" fill="#ffe14d" stroke="${OUT}" stroke-width="3"/>
      <path d="M118 62 Q124 40 136 30" stroke="${OUT}" stroke-width="4" fill="none"/><circle cx="138" cy="28" r="8" fill="#ffe14d" stroke="${OUT}" stroke-width="3"/>
      <g class="arm-i">${lim('M44 128 Q22 140 26 166', d, 9)}${lim('M156 128 Q178 140 174 166', d, 9)}</g>
      <g class="arm-r">${lim('M44 120 Q16 110 20 76', d, 9)}${lim('M156 120 Q184 110 180 76', d, 9)}</g>
      <path d="M38 152 Q36 58 100 58 Q164 58 162 152 Q156 200 142 172 Q130 208 116 176 Q100 212 84 176 Q70 208 58 172 Q44 200 38 152 Z" fill="${c}" stroke="${OUT}" stroke-width="4" stroke-linejoin="round"/>
      <ellipse cx="60" cy="132" rx="9" ry="6" fill="#ff9ccb"/><ellipse cx="140" cy="132" rx="9" ry="6" fill="#ff9ccb"/>
      <ellipse cx="72" cy="80" rx="15" ry="8" fill="#fff" opacity=".3" transform="rotate(-30 72 80)"/>
      ${eye(78, 108, 17, '#0bb5c9', -1)}${eye(122, 108, 17, '#0bb5c9', 1)}${mouth(100, 146, 56, 20)}</g>`;
  }},
];
const mon = id => MONS.find(m => m.id === id);
function sprite(el, id) {
  el.innerHTML = `<svg viewBox="0 0 200 222" aria-hidden="true">${mon(id).draw()}</svg><span class="roartag">ROAAAR!</span>`;
}
function pose(el, p) { el.classList.toggle('roar', p === 'roar'); el.classList.toggle('sad', p === 'sad'); }

/* =========================================================
   State
   ========================================================= */
const $ = s => document.querySelector(s);
const MIN_HOLD = 200, ROW_MAX = 500, TH_MIN = 100, TH_MAX = 4000;
const S = {
  esp: false, online: false, forceSim: /[?&]sim=1/.test(location.search),
  amp: 0, players: [{ m: null, name: '' }, { m: null, name: '' }],
  rounds: 3, roarMs: 3000, turn: 0, scores: [[], []], phase: 'select',
  th: 2000, thHoldUntil: 0, btnSeq: null, roarSeq: null,
  roar: null, timers: [], simHeld: false, simAmp: 12, mic: null,
};
const cur = () => S.turn % 2, rnd = () => Math.floor(S.turn / 2);
const pname = i => S.players[i].name || `P${i + 1}`;
const total = i => S.scores[i].reduce((a, s) => a + (s ? s.total : 0), 0);
const later = (fn, ms) => S.timers.push(setTimeout(fn, ms));
const clearTimers = () => { S.timers.forEach(clearTimeout); S.timers = []; };

/* =========================================================
   Hardware link (ESP32 /api/*)  — falls back to simulation
   ========================================================= */
function sendCmd(c) {
  if (!S.online) return;
  fetch('/api/cmd?c=' + encodeURIComponent(c), { cache: 'no-store' }).catch(() => {});
}
async function poll() {
  if (!S.forceSim) {
    try {
      const r = await fetch('/api/status', { cache: 'no-store' });
      const d = await r.json();
      S.esp = true; setOnline(!!d.online);
      if (d.online) {
        onSample(d.amp);
        if (S.phase === 'ready' && Date.now() > S.thHoldUntil && d.alert !== S.th) setTh(d.alert, false);
        if (S.btnSeq !== null && d.btnSeq !== S.btnSeq) onHwButton();
        S.btnSeq = d.btnSeq;
        if (S.roarSeq !== null && d.roarSeq !== S.roarSeq) finishRoar({ peak: d.roarPeak, hold: d.roarHold, src: 'STM32' });
        S.roarSeq = d.roarSeq;
      }
    } catch (e) { S.esp = false; setOnline(false); }
  }
  setTimeout(poll, S.esp ? 110 : 2500);
}
function setOnline(v) {
  const was = S.online; S.online = v && !S.forceSim;
  const c = $('#conn'), sim = S.forceSim;
  c.textContent = S.online ? 'STM32 Online' : sim ? 'โหมดจำลอง (?sim=1)' : (S.esp ? 'รอ STM32… (เช็คสาย UART/GND)' : 'ไม่เจอ ESP32');
  c.className = 'pill ' + (S.online ? 'ok' : 'sim');
  $('#selConn').textContent = S.online ? 'เชื่อมต่อบอร์ดแล้ว ✓ ใช้เสียงจาก KY-037'
    : sim ? 'โหมดจำลองสำหรับนักพัฒนา: SPACE ค้าง = ค่าสุ่มแทนเสียง, Enter = ปุ่ม KY-040'
    : 'รอเชื่อมต่อ STM32… ต้องต่อบอร์ดก่อนถึงจะเริ่มเกมได้';
  $('#simRoar').classList.toggle('hidden', !sim);
  $('#goHint').textContent = S.online ? 'หรือกดปุ่มบน KY-040 · คำรามใส่ไมค์ KY-037'
    : sim ? 'Enter = ปุ่ม KY-040 · SPACE ค้าง = ค่าสุ่มแทนเสียง' : 'บอร์ดหลุด — รอ STM32 กลับมา';
  if (S.phase === 'ready') $('#go').disabled = !(S.online || sim);
  if (S.phase === 'select') refreshSelect();
  if (S.online && !was && S.phase !== 'select') { sendCmd('GAME,1'); pushTh(); syncLed(); }
}

/* Dev-only simulation (open with ?sim=1): random fake amplitude while SPACE is held.
   Normal play uses ONLY the KY-037 amplitude streamed by the STM32. */
if (S.forceSim) setInterval(() => {
  const target = S.simHeld ? 2300 + Math.random() * 1700 : 10 + Math.random() * 14;
  S.simAmp += (target - S.simAmp) * (S.simHeld ? .35 : .45);
  onSample(Math.round(S.simAmp));
}, 50);

/* =========================================================
   Live samples
   ========================================================= */
function onSample(a) {
  S.amp = a;
  $('#ampv').textContent = a;
  $('#mfill').style.width = Math.min(100, a / 4095 * 100) + '%';
  if (S.phase === 'roar' && S.roar) {
    const now = performance.now(), R = S.roar;
    if (a > R.peak) R.peak = a;
    if (a >= R.th) R.hold += Math.min(now - R.t, 150);
    R.t = now;
    $('#pkv').textContent = R.peak; $('#holdv').textContent = (R.hold / 1000).toFixed(2) + 's';
    $('#mpk').style.left = Math.min(100, R.peak / 4095 * 100) + '%'; $('#mpk').style.opacity = 1;
    pose($('#spr' + cur()), a >= R.th * .6 ? 'roar' : 'idle');
  }
}

/* =========================================================
   Threshold
   ========================================================= */
let thTimer = 0;
function setTh(v, fromUser) {
  v = Math.max(TH_MIN, Math.min(TH_MAX, Math.round(v / 25) * 25));
  S.th = v; $('#th').value = v; $('#thv').textContent = v;
  $('#mth').style.left = (v / 4095 * 100) + '%';
  if (fromUser) { clearTimeout(thTimer); thTimer = setTimeout(pushTh, 120); S.thHoldUntil = Date.now() + 1500; }
}
function pushTh() { S.thHoldUntil = Date.now() + 1200; sendCmd('SET_TH,' + S.th); }
$('#th').addEventListener('input', e => setTh(+e.target.value, true));
$('#presets').addEventListener('click', e => { if (e.target.dataset.v) setTh(+e.target.dataset.v, true); });
function lockTh(lock) { $('#th').disabled = lock; $('#presets').querySelectorAll('button').forEach(b => b.disabled = lock); }

/* =========================================================
   Lamps (mirrored on the KY-009 via LED,* commands)
   ========================================================= */
let ledMode = 'OFF';
function lamps(mode) {
  ledMode = mode;
  const g = $('#lampG'), y = $('#lampY'), r = $('#lampR');
  [g, y, r].forEach(l => l.classList.remove('on', 'fade', 'blink'));
  if (mode === 'Y') y.classList.add('on');
  if (mode === 'F') { y.classList.add('on'); void y.offsetWidth; y.classList.add('fade'); y.classList.remove('on'); }
  if (mode === 'G') g.classList.add('on');
  if (mode === 'R') r.classList.add('on', 'blink');
}
function syncLed() { if (ledMode !== 'F') sendCmd('LED,' + ledMode); }

/* =========================================================
   Board rendering
   ========================================================= */
function buildRows() {
  for (const p of [0, 1]) {
    $('#rows' + p).innerHTML = [5, 4, 3, 2, 1, 0].map(r =>
      `<div class="row" data-r="${r}"><em>${r + 1}</em><div class="seg"><div class="segfill"></div></div><span class="pts"></span></div>`).join('');
  }
}
function render() {
  const tots = [total(0), total(1)];
  const scale = Math.max(S.rounds * 300, Math.max(...tots) * 1.08);
  for (const p of [0, 1]) {
    $('#rows' + p).querySelectorAll('.row').forEach(row => {
      const r = +row.dataset.r, sc = S.scores[p][r];
      row.classList.toggle('dim', r >= S.rounds);
      row.classList.toggle('cur', S.phase !== 'over' && cur() === p && rnd() === r);
      row.classList.toggle('fail', !!sc && !sc.pass);
      row.querySelector('.segfill').style.width = sc ? Math.min(100, sc.total / ROW_MAX * 100) + '%' : '0';
      row.querySelector('.pts').textContent = sc ? (sc.pass ? sc.total : '✕') : '';
    });
    $('#tot' + p).textContent = tots[p];
    $('#fill' + p).style.height = Math.min(100, tots[p] / scale * 100) + '%';
    document.querySelector(`.side[data-p="${p}"]`).classList.toggle('active', S.phase !== 'over' && cur() === p);
  }
  const p = cur();
  $('#hudTurn').innerHTML = S.phase === 'over' ? 'จบเกม' :
    `รอบ ${rnd() + 1}/${S.rounds} · ตาของ<span class="who" style="background:${p ? 'rgba(255,90,77,.2)' : 'rgba(70,211,106,.2)'};color:${p ? 'var(--p2)' : 'var(--p1)'}">${esc(pname(p))} · ${mon(S.players[p].m).name}</span>`;
}
function big(t, s, cls, bar) {
  const b = $('#bigmsg');
  b.className = cls || ''; b.querySelector('.t').textContent = t; b.querySelector('.s').textContent = s || '';
  b.querySelector('.pbar').classList.toggle('hidden', !bar);
  void b.offsetWidth; b.classList.add('pop');
}
const hideBig = () => $('#bigmsg').classList.add('hidden');
const esc = s => s.replace(/[&<>"]/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

/* =========================================================
   Scoring
   ========================================================= */
function score(peak, hold, th, win) {
  hold = Math.round(hold);
  const pass = peak >= th && hold >= MIN_HOLD;
  if (!pass) return { pass, peak, hold, th, base: 0, over: 0, sus: 0, total: 0,
    why: peak < th ? `peak ${peak} ไม่ถึง ${th}` : `ดังเกินเกณฑ์แค่ ${(hold / 1000).toFixed(2)} วิ (ต้อง ≥ 0.2)` };
  const base = Math.round(th / 10), over = Math.round((peak - th) / 20), sus = Math.round(Math.min(1, hold / win) * 100);
  return { pass, peak, hold, th, base, over, sus, total: base + over + sus };
}
function showLast(sc, who, src) {
  $('#lastRes').innerHTML = `
    <div class="res-line"><span>${esc(who)}</span><b>${src}</b></div>
    <div class="res-line"><span>threshold / peak</span><b>${sc.th} / ${sc.peak}</b></div>
    <div class="res-line"><span>ดังเกินเกณฑ์รวม</span><b>${(sc.hold / 1000).toFixed(2)} วิ</b></div>
    ${sc.pass ? `<div class="res-line"><span>ความกล้า + ดังเกิน + ความอึด</span><b>${sc.base} + ${sc.over} + ${sc.sus}</b></div>
      <div class="res-total ok">+${sc.total} คะแนน</div>` : `<div class="res-total bad">ไม่ผ่าน · 0</div><div class="hint">${sc.why}</div>`}`;
}

/* =========================================================
   Game flow:  ready(Y) → countdown(Y fades 3s) → roar → result(G/R) → next
   ========================================================= */
function enterReady() {
  S.phase = 'ready'; S.roar = null;
  lamps('Y'); sendCmd('LED,Y'); lockTh(false);
  $('#go').disabled = !(S.online || S.forceSim); $('#mpk').style.opacity = 0; $('#pkv').textContent = '–'; $('#holdv').textContent = '–';
  [0, 1].forEach(i => pose($('#spr' + i), 'idle'));
  hideBig(); $('#go').textContent = `เริ่มตา ${pname(cur())}`;
  render();
}
function startTurn() {
  if (S.phase !== 'ready') return;
  S.phase = 'countdown'; lockTh(true); $('#go').disabled = true;
  pushTh(); lamps('F'); sendCmd('LED,F');
  [3, 2, 1].forEach((n, i) => later(() => big(String(n), `${pname(cur())} · threshold ${S.th}`), i * 1000));
  later(beginRoar, 3000);
}
function beginRoar() {
  S.phase = 'roar';
  S.roar = { peak: 0, hold: 0, t: performance.now(), th: S.th, player: cur(), round: rnd() };
  lamps('OFF');
  big('ROAR!', `ดังเกิน ${S.th} ให้นานที่สุด`, '', true);
  const bar = $('#bigmsg .pbar i');
  bar.style.transition = 'none'; bar.style.transform = 'scaleX(1)'; void bar.offsetWidth;
  bar.style.transition = `transform ${S.roarMs}ms linear`; bar.style.transform = 'scaleX(0)';
  if (S.online) {
    sendCmd(`ROAR,${S.th},${S.roarMs}`);
    // STM32 replies with RES,<peak>,<hold>,<pass>; fall back to web-side samples if it never arrives
    later(() => { if (S.phase === 'roar') { S.phase = 'wait'; big('…', 'รอผลจาก STM32'); } }, S.roarMs);
    later(() => finishRoar({ peak: S.roar.peak, hold: S.roar.hold, src: 'เว็บ (STM32 ไม่ตอบ)' }), S.roarMs + 1500);
  } else {
    later(() => finishRoar({ peak: S.roar.peak, hold: S.roar.hold, src: 'จำลอง' }), S.roarMs);
  }
}
function finishRoar(res) {
  if ((S.phase !== 'roar' && S.phase !== 'wait') || !S.roar) return;
  clearTimers();
  const { player: p, round: r, th } = S.roar;
  const sc = score(res.peak, res.hold, th, S.roarMs);
  S.scores[p][r] = sc; S.phase = 'result';
  lamps(sc.pass ? 'G' : 'R');            // STM32 sets its own KY-009 G/R at the end of ROAR
  const el = $('#spr' + p);
  pose(el, sc.pass ? 'roar' : 'sad');
  if (sc.pass) later(() => pose(el, 'idle'), 1400);
  big(sc.pass ? `+${sc.total}` : 'ไม่ผ่าน!', sc.pass ? `peak ${sc.peak} · ${(sc.hold / 1000).toFixed(2)} วิ` : sc.why, sc.pass ? 'pass' : 'fail');
  showLast(sc, `${pname(p)} รอบ ${r + 1}`, res.src);
  render();
  later(nextTurn, 2800);
}
function nextTurn() {
  S.turn++;
  if (S.turn >= S.rounds * 2) return endGame();
  enterReady();
}
function endGame() {
  S.phase = 'over'; hideBig(); lamps('OFF'); sendCmd('LED,OFF'); render();
  const t = [total(0), total(1)];
  const w = t[0] === t[1] ? -1 : (t[0] > t[1] ? 0 : 1);
  if (w >= 0) {
    sprite($('#sprWin'), S.players[w].m); pose($('#sprWin'), 'roar');
    pose($('#spr' + w), 'roar'); pose($('#spr' + (1 - w)), 'sad');
    $('#winTitle').textContent = `${pname(w)} ชนะ!`;
    $('#winSub').textContent = `${mon(S.players[w].m).name} ${t[w]} : ${t[1 - w]} ${mon(S.players[1 - w].m).name}`;
    if (S.online) sendCmd('LED,G');
  } else {
    $('#sprWin').innerHTML = ''; $('#winTitle').textContent = 'เสมอ!'; $('#winSub').textContent = `${t[0]} : ${t[1]}`;
  }
  $('#end').classList.remove('hidden');
}
function onHwButton() {
  if (S.phase === 'ready') startTurn();
  else if (S.phase === 'over') newGame();
}
function newGame() {
  clearTimers(); $('#end').classList.add('hidden');
  S.turn = 0; S.scores = [[], []];
  for (const p of [0, 1]) {
    sprite($('#spr' + p), S.players[p].m);
    $('#plate' + p).textContent = pname(p).toUpperCase();
    $('#sname' + p).textContent = mon(S.players[p].m).name;
  }
  $('#lastRes').textContent = 'ยังไม่มีผล';
  sendCmd('GAME,1'); pushTh();
  enterReady();
}

/* =========================================================
   Select screen
   ========================================================= */
/* One shared grid: Player 1 picks first, then Player 2. A picked monster gets that
   player's colour frame and can't be picked again. */
function buildSelect() {
  const box = $('#cards');
  box.innerHTML = MONS.map(m => `<button class="mcard" data-m="${m.id}"><i class="badge"></i><div class="spr"></div><b style="color:${m.color}">${m.name}</b><span>${m.tag}</span></button>`).join('');
  box.querySelectorAll('.mcard').forEach(b => {
    const spr = b.querySelector('.spr');
    sprite(spr, b.dataset.m);
    b.addEventListener('click', () => {
      const p = S.players[0].m ? (S.players[1].m ? -1 : 1) : 0;
      if (p < 0 || S.players.some(x => x.m === b.dataset.m)) return;
      S.players[p].m = b.dataset.m; refreshSelect();
      pose(spr, 'roar'); setTimeout(() => pose(spr, 'idle'), 900);
    });
    b.addEventListener('mouseenter', () => { if (!b.disabled) pose(spr, 'roar'); });
    b.addEventListener('mouseleave', () => pose(spr, 'idle'));
  });
  $('#repick').addEventListener('click', () => { S.players[0].m = S.players[1].m = null; refreshSelect(); });
  refreshSelect();
}
function refreshSelect() {
  const turn = S.players[0].m ? (S.players[1].m ? -1 : 1) : 0;
  $('#cards').querySelectorAll('.mcard').forEach(b => {
    const by = S.players.findIndex(x => x.m === b.dataset.m);
    b.classList.toggle('by0', by === 0); b.classList.toggle('by1', by === 1);
    b.querySelector('.badge').textContent = by >= 0 ? 'P' + (by + 1) : '';
    b.disabled = by >= 0 || turn < 0;
  });
  for (const p of [0, 1]) {
    document.querySelector(`.pslot[data-p="${p}"]`).classList.toggle('turn', turn === p);
    const m = S.players[p].m, el = $('#pick' + p);
    el.textContent = m ? mon(m).name : 'ยังไม่เลือก'; el.style.color = m ? mon(m).color : '';
  }
  const pp = $('#pickPrompt');
  pp.textContent = turn < 0 ? 'พร้อมแล้ว! กดเริ่มเกม' : `PLAYER ${turn + 1} เลือกตัวละคร`;
  pp.style.color = turn === 0 ? 'var(--p1)' : turn === 1 ? 'var(--p2)' : 'var(--amber)';
  $('#repick').classList.toggle('hidden', !S.players[0].m);
  $('#startGame').disabled = !(turn < 0 && (S.online || S.forceSim));
}
$('#startGame').addEventListener('click', () => {
  S.players[0].name = $('#pn0').value.trim(); S.players[1].name = $('#pn1').value.trim();
  S.rounds = +$('#optRounds').value; S.roarMs = +$('#optRoar').value;
  $('#select').classList.add('hidden'); $('#game').classList.remove('hidden');
  buildRows(); newGame();
});
function toSelect() {
  clearTimers(); S.phase = 'select'; lamps('OFF'); sendCmd('LED,OFF'); sendCmd('GAME,0');
  $('#end').classList.add('hidden'); $('#game').classList.add('hidden'); $('#select').classList.remove('hidden');
}
$('#quit').addEventListener('click', toSelect);
$('#reselect').addEventListener('click', toSelect);
$('#again').addEventListener('click', newGame);
$('#go').addEventListener('click', startTurn);
const sim = $('#simRoar');
sim.addEventListener('pointerdown', e => { S.simHeld = true; sim.classList.add('held'); sim.setPointerCapture(e.pointerId); });
['pointerup', 'pointercancel'].forEach(ev => sim.addEventListener(ev, () => { S.simHeld = false; sim.classList.remove('held'); }));
addEventListener('keydown', e => {
  if (e.target.tagName === 'INPUT' && e.target.type !== 'range') return;
  if (!S.forceSim || S.phase === 'select') return;
  if (e.code === 'Space') { e.preventDefault(); S.simHeld = true; }
  if (e.code === 'Enter') { e.preventDefault(); onHwButton(); }
});
addEventListener('keyup', e => { if (e.code === 'Space') S.simHeld = false; });

buildSelect(); setTh(S.th, false); setOnline(false); poll();
</script>
</body>
</html>
)DECIBOO";
